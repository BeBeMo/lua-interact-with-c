#include<iostream>
#include<string.h>

using namespace std;

extern "C"
{
	#include "../../slua/include/lua.h"
	#include "../../slua/include/lauxlib.h"
	#include "../../slua/include/lualib.h"
}
int main(int argc,char *argv[])
{
	//1. create lua state
	lua_State *L = luaL_newstate();
	if(L == NULL)
	{
		return 0;
	}
	
	//2. load lua file
	int bRet = luaL_loadfile(L,"test.lua");
	if(bRet)
	{
		string strLoadFileErrMsg = lua_tostring(L,-1);
		cout <<"load file error"<<strLoadFileErrMsg<<endl;
		return 0;
	}
	
	//3. run lua file
	bRet = lua_pcall(L,0,0,0);
	if(bRet)
	{
		cout <<"pcall error"<<endl;
		return 0;
	}

	//4. get variable
	lua_getglobal(L,"str");
	string str = lua_tostring(L,-1);
	cout<<"str = "<<str.c_str()<<endl;		//str = this is lua
	
	//5. get table
	lua_getglobal(L,"tbl");
	lua_getfield(L,-1,"name");
	str = lua_tostring(L,-1);
	cout <<"tbl:name = "<<str.c_str()<<endl;	//tbl:name = mao

	//6. get function
	lua_getglobal(L,"add");				//get function,and push it into the stack
	lua_pushnumber(L,10);				//push the first parameter into the stack
	lua_pushnumber(L,20);				//push the second parameter into the stack
	int iRet = lua_pcall(L,2,1,0);			//push the return value into thr stack. 2 means the number of parameters. 1 means the number of return value
	if(iRet)					//get function error
	{
		const char *pErrorMsg = lua_tostring(L,-1);
		cout << pErrorMsg <<endl;
		lua_close(L);
		return 0;
	}
	if(lua_isnumber(L,-1))				//print the return value
	{
		double fValue = lua_tonumber(L,-1);
		cout <<"Result is "<< fValue <<endl;
	}
	
	//7. close state
	lua_close(L);
	return 0;
}
