# lua and c++
### part1: c++ interact with lua
&ensp;&ensp;Lua is usually used as config file, like .ini , .xml  

&ensp;&ensp;In this project, we use cpp load the variable, table, function in the lua script.
###### compile command:
	cd src/c++-call-lua
	g++ -o test test.cpp -I ../../slua/include/  -L ../../slua/lib/ ../../slua/lib/linux/liblua.a
###### run command :
	./test
###### the output result :
```
str = this is lua
tbl:name = mao
Result is 30
```
### part2: lua interact with c++
&ensp;&ensp;We create a module function in cpp file, register it to the lua interpreter, and cpp file execute the lua script. At last, in the lua script ,we call the registered function.
###### compile command:
	cd src/lua-call-c++
	g++ -o test test.cpp -I ../../slua/include/  -L ../../slua/lib/ ../../slua/lib/linux/liblua.a -ldl
###### run command :
	./test
###### the output result :
```
The average is 	30
The sum is 	150
Please enter to exit ...
```
