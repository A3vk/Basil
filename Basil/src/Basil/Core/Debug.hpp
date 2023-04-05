#pragma once

/*
 * Static Properties:
 * developerConsoleVisible:	Reports whether the development console is visible. The development console automatically appears when an error has been logged. For example:
 * isDebugBuild:	In the Build Settings dialog there is a check box called "Development Build".
 * unityLogger:	Get default debug logger.
 *
 * Static Methods
 * Assert:	Assert a condition and logs an error message to the Unity console on failure.
 * AssertFormat:	Assert a condition and logs a formatted error message to the Unity console on failure.
 * Break:	Pauses the editor.
 * ClearDeveloperConsole:	Clears errors from the developer console.
 * DrawLine:	Draws a line between specified start and end points.
 * DrawRay:	Draws a line from start to start + dir in world coordinates.
 * ExtractStackTraceNoAlloc:	Populate an unmanaged buffer with the current managed call stack as a sequence of UTF-8 bytes, without allocating GC memory. Returns the number of bytes written into the buffer.
 * Log:	Logs a message to the Unity Console.
 * LogAssertion:	A variant of Debug.Log that logs an assertion message to the console.
 * LogAssertionFormat:	Logs a formatted assertion message to the Unity console.
 * LogError:	A variant of Debug.Log that logs an error message to the console.
 * LogErrorFormat:	Logs a formatted error message to the Unity console.
 * LogException:	A variant of Debug.Log that logs an error message from an exception to the console.
 * LogFormat:	Logs a formatted message to the Unity Console.
 * LogWarning:	A variant of Debug.Log that logs a warning message to the console.
 * LogWarningFormat:	Logs a formatted warning message to the Unity Console.
 * RetrieveStartupLogs:	Returns any captured startup logs
 */
class Debug
{
public:
    static void Init();

    
};
