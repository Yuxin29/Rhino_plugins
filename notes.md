# 3.31

## DONE
- installed vs, rhino sdk...
- build a 2-cmd(printf) plug-in

## round-table review
- One other non-destructive feature in Rhino: edge softening
- Command Reimplementation (a few weeks): a box,  filleted by all edges
- SDK Keywords searching*(
	- "C:\Program Files\Rhino 8 SDK\inc\IAutoUIExtraRequirements.h")*
	- eg: CRhinoFilletEdge, Filleting
- debugging: local window debuggers

# 4.1

// TODO
- ask git repo within LBP (Josh)
- play a few fundamentals SDK cmds

## shourtcuts
- ctrl + 0, ctrl + G
- ctrl + shift + B

## this and that:
- wchar_t: wide character, supporting CN,KO,JP... and unicode
	- char: 1 byte
	- wchar_t: 2 / 4 bytes
- bool VS BOOL
	- bool, C++ type, T or F, 2 bytes
	- BOOL, windows type, used in Windows API / Rhino SDK, "typedef int BOOL", 4 bytes
- how does a rhino-plugin work
	- App: on MFC, the lifespan of the DLL, shell of the plugin
	- Plugin: on Rhino, implementation of the plugin
