# lua-lz4
* LZ4 fast compression algorithm binding for Lua 
* LZ4 fast compression algorithm binding for Unity
* LZ4 fast compression algorithm binding for xLua

## what ?

## todo
1.增加unity linux、webgl 的支持
...

## how to used?

* 编译库

 1. 查看unity目录下的文件，使用指定平台的编译工具就可编译
 2. 也可使用unity/bin目录编译好的的文件到直接集成到unity中，也可集成到自己的项目中

* c的直接调用

```cpp
     char* rawchar = "想要在C#和C++之间进行字符串传递会涉及到两件事情想要在C#和C++之间进行字符串传递会涉及到两件事情想要在C#和C++之间进行字符串传递会涉及到两件事情想要在C#和C++之间进行字符串传递会涉及到两件事情=>>>>>!";
    char *outc = (char*)malloc(1000);
    int ret = UnityLz4Compress(rawchar,strlen(rawchar),outc);
    std::cout << outc << ":" << strlen(outc);
    
    buffer inbufer(outc, ret);
    ret = Unitylz4Decompress((char*)inbufer.getPtr(),ret,outc);
    std::string data(outc,ret);
    std::cout << "buffer len:" << data.length()          << std::endl;
    std::cout << "strlen len:"<< data   << std::endl;
    return 0;
```
* c# 可用下面的方式来使用，入口请看代码的test函数

```c#
using System;
using System.Runtime.InteropServices;
using System.Text;

internal class Native {
	#region LZ4DLL
	#if (UNITY_IPHONE || UNITY_WEBGL) && !UNITY_EDITOR
	const string LZ4DLL = "__Internal";
	#else
	const string LZ4DLL = "Lz4forUnity";
	#endif
	#endregion
	
	#region NativeAPI
	[DllImport(LZ4DLL)] private static extern string UnityLz4Version();

	[DllImport(LZ4DLL)] private static extern int UnityLz4Compress(byte[] str,int inlen,ref byte outPtr);

	[DllImport(LZ4DLL)] private static extern int Unitylz4Decompress(byte[] str,int inlen,ref byte outPtr);
	#endregion

	#region Lua-lz4
	[System.Obsolete("未测试的接口",true)]
	[DllImport(LZ4DLL)] private static extern int UnityLuaLz4Init(System.IntPtr L);
	#endregion

	#region Lua-lz4-Csharp 

	[XLua.LuaCallCSharp]
	public class Lz4 {

		[XLua.LuaCallCSharp]
		public static string GetVersion(){
			return UnityLz4Version();
		}

		[XLua.LuaCallCSharp]
		public static byte[] Compress(byte[] bytes,int outBufferMaxLen) {
			byte[] outBuffer = new byte[outBufferMaxLen];
			int size =  UnityLz4Compress(bytes,bytes.Length,ref outBuffer[0]);
			byte[] ret = new byte[size];
			Array.Copy(outBuffer,ret,size);
			return ret;
		}

		[XLua.LuaCallCSharp]
		public static byte[] Compress(string str,int outBufferMaxLen) {
			byte[] bytes = System.Text.Encoding.UTF8.GetBytes(str);
			return Compress(bytes,outBufferMaxLen);
		}

		[XLua.LuaCallCSharp]
		public static byte[] DeCompress(byte[] bytes,int outBufferMaxLen){
           	byte[] outBuffer = new byte[outBufferMaxLen];
			int size =  Unitylz4Decompress(bytes,bytes.Length,ref outBuffer[0]);
			byte[] ret = new byte[size];
			Array.Copy(outBuffer,ret,size);
			return ret;
		}

		[XLua.LuaCallCSharp]
		public static byte[] DeCompress(string str,int outBufferMaxLen){
           	byte[] bytes = System.Text.Encoding.UTF8.GetBytes(str);
			return DeCompress(bytes,outBufferMaxLen);
		}

		public static void PerformanceTesting(string str,int outBufferMaxLen){
           	return ;
		}

	    public static void TestLz4(XLua.LuaEnv env){
			const int MAX_BUFFER_LEN = 1000;
			string rawstr = "想要在C#和C++之间进行字符串传递会涉及到两件事情想要在C#和C++之间进行字符串传递会涉及到两件事情想要在C#和C++之间进行字符串传递会涉及到两件事情想要在C#和C++之间进行字符串传递会涉及到两件事情!!!";
			string v = Native.Lz4.GetVersion();
			UnityEngine.Debug.Log("------>lz4 version:" + v);
			byte[] bytes = System.Text.Encoding.UTF8.GetBytes(rawstr);
			byte[] a = Native.Lz4.Compress(bytes,MAX_BUFFER_LEN);
			UnityEngine.Debug.Log("a:" + a.Length + "---" + System.Text.Encoding.UTF8.GetString(a));
			byte[] b = Native.Lz4.DeCompress(a,MAX_BUFFER_LEN);
			UnityEngine.Debug.Log("b:" + b.Length + "---" + System.Text.Encoding.UTF8.GetString(b));
			// throw new System.Exception( System.Text.Encoding.UTF8.GetString(b));
			//lua api 注册
			// System.IntPtr L = env.L;
			//int ret = Native.UnityLuaLz4Init(L);
			// Debug.Log("--> lua lz4 初始化成功");
		}
	}

	#endregion
}
```
* lua的调用要依赖上面的C# 的实现

```lua
    ------------------------------------------------------------------------------
    local str = "测试测试测试测试测试测试测试测试测试测试测试测试测试测试测试测试测试测试测试测试！";
    local max_buf = 512;
    local val = CS.Native.Lz4.DeCompress(CS.Native.Lz4.Compress(str,max_buf),max_buf);
    print("压缩解压消耗的时间:",os.clock()-time,"长度:",#val);
    assert(#str == #val,"解压失败！");
    ------------------------------------------------------------------------------
```

## content us

qq:371741579
email:czjone@126.com
