#include<iostream>
#include<string.h>
using namespace std;

extern "C"
{
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}
void main()
{
	//1.create Lua state
	lua_State *L = luaL_newstate();
	if(L == NULL)
	{
		return ;
	}

	//2.load lua file
	int bRet = luaL_loadfile(L,"hello.lua");
	if(bRet)
	{
		cout<<"load file error"<<endl;
		return ;
	}

	//3.run lua file
	bRet = lua_pcall(L,0,0,0);
	if(bRet)
	{
		cout<<"pcall error"<<endl;
		return ;
	}
	
	//4.get variable
	lua_getglobal(L,"str");
	string str = lua_tostring(L,-1);
	cout<<"str = "<<str.c_str()<<endl;		//str = this is lua

	//5.read table
	lua_getglobal(L,"tb1");
	lua_getfield(L,-1,"name");
	str = lua_tostring(L,-1);
	cout<<"tb1:name = "<<str.c_str()<<endl;		//tb1:name = mao

	//6.read function
	lua_getglobal(L,"add");				//get function,push it into the stack
	lua_pushnumber(L,10);				//press the first parameter
	lua_pushnumber(L,20);				//press the second parameter
	int iRet = lua_pcall(L,2,1,0);			//call function,after finish call,will press the return value to the stack. 2 means the number of parameters. 1 means the number of return value.
	if(iRet)
	{
		const char *pErrorMsg = lua_tostring(L,-1);
		cout << pErrorMsg << endl;
		lua_close(L);
		return ;
	}
	if(lua_isnumber(L,-1))
	{
		double fValue = lua_tonumber(L,-1);
		cout <<"Result is "<< fValue << endl;
	}
	lua_close(L);
	return ;
}

