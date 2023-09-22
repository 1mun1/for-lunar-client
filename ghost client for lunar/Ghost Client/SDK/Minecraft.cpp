#include "Minecraft.h"

jclass CMinecraft::GetClass()
{
	return lc->GetClass("net.minecraft.client.Minecraft");
}

jobject CMinecraft::GetInstance()
{
	jclass minecraftClass = this->GetClass();

	jfieldID getMinecraft = lc->env->GetStaticFieldID(minecraftClass, "theMinecraft", "Lnet/minecraft/client/Minecraft;");
	jobject rtrn = lc->env->GetStaticObjectField(minecraftClass, getMinecraft);

	lc->env->DeleteGlobalRef(minecraftClass);

	return rtrn;
}

CPlayer CMinecraft::GetLocalPlayer()
{
	jclass minecraftClass = this->GetClass();
	jobject minecraftObject = this->GetInstance();

	jfieldID getPlayer = lc->env->GetFieldID(minecraftClass, "thePlayer", "Lnet/minecraft/client/entity/EntityPlayerSP;"); //L + Lnet/minecraft/client/entity/EntityPlayerSP + ;
	jobject rtrn = lc->env->GetObjectField(minecraftObject, getPlayer);

	lc->env->DeleteGlobalRef(minecraftClass);
	lc->env->DeleteGlobalRef(minecraftObject);

	return CPlayer(rtrn);
}