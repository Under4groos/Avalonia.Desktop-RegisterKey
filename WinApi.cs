using System;
using System.Runtime.InteropServices;

/////////////////////////////////////

public static class Lib
{
    public const string USER = "user32.dll";
    public const string WinShellLib = "WinShellLib.dll";
}


#region RegisterHotKey
[DllImport(Lib.USER)]
public static extern bool RegisterHotKey(IntPtr hWnd, int id, int fsModifiers, int vk);
public static bool RegisterHotKeyBind(IntPtr hWnd, key_Modifiers fsModifiers, WinFormKeys vk)
{
    return RegisterHotKey(hWnd, 0, (int)fsModifiers, (int)vk);
}

// using WInFormKeys 
[DllImport(Lib.WinShellLib)]
public static extern bool _RegisterHotKey(IntPtr hWnd, int nIndex, int vk);
public static bool _RegisterHotKeyBind(IntPtr hWnd, int nIndex, WinFormKeys vk)
{
    return _RegisterHotKey(hWnd, nIndex, (int)vk);
}
#endregion

[DllImport(Lib.WinShellLib)]
public static extern int _GetMessage();