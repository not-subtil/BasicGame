@echo off

REM Review CommonCompilerFlags
set CommonLinkerFlags= -incremental:no -opt:ref user32.lib
set CommonCompilerFlags= -MTd -nologo -Gm- -GR- -EHa- -Od -Oi -WX -W4 -wd4201 -wd4100 -wd4189 -wd4505 -wd4702 -wd4244 -FC -Z7

IF NOT EXIST ..\..\BasicGame_Build mkdir ..\..\BasicGame_Build
pushd ..\..\BasicGame_Build

REM 32-bit build
cl %CommonCompilerFlags% ..\BasicGame\code\main.cpp /link %CommonLinkerFlags%
popd