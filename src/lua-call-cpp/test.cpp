#include<stdio.h>

extern "C"
{
	#include "../../slua/include/lua.h"	
	#include "../../slua/include/lualib.h"
	#include "../../slua/include/lauxlib.h"
}
lua_State* L;		//a pointer to the lua interpreter
static int average(lua_State *L)
{
	int n = lua_gettop(L);				//get the number of params
	double sum = 0;

	for(int i = 1;i <= n;i++)			//get the sum of params
	{
		sum+=lua_tonumber(L,i);
	}
	lua_pushnumber(L,sum/n);			//put the average value into the stack
	lua_pushnumber(L,sum);				//put the sum value into the stack
	return 2;					//return the number of return values
}


int main(int argc,char *argv[])
{
	L = luaL_newstate();					//init lua
	luaL_openlibs(L);				//load lua basic libs
	lua_register(L,"average",average);		//register function
	luaL_dofile(L,"avg.lua");			//run script
	lua_close(L);					//clear lua

	printf("Please enter to exit ...");		//pause
	getchar();
	return 0;
}
