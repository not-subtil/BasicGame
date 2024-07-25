@echo off

REM Review CommonCompilerFlags
set CommonLinkerFlags= -incremental:no -opt:ref user32.lib
set CommonCompilerFlags= -MTd -nologo -Gm- -GR- -EHa- -Od -Oi -WX -W4 -wd4201 -wd4100 -wd4189 -wd4505 -wd4702 -wd4244 -FC -Z7

IF NOT EXIST ..\..\basic_game_build mkdir ..\..\basic_game_build
pushd ..\..\basic_game_build

REM 32-bit build
cl %CommonCompilerFlags% ..\basic_game\code\main.cpp /link %CommonLinkerFlags%
popd