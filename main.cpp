bool Hooking;
void (*hook) (void* _this, float value);
void (*_update)(void *instance);
void update(void *instance) {
	if(instance != NULL) {
		if(Hooking) {
		hook(instance, 999);
		}
	}
	_update(instance);
}


hook = (void(*)(void *, float))getAbsoluteAddress(targetLibName, 0x000000); // put your void Offset   
MSHookFunction((void *)getAbsoluteAddress("libil2cpp.so", 0x000000), (void *) update, (void **) &_update); // put update Offset


OBFUSCATE("0_Toggle_Hooking"),
            


case 0:
Hooking = boolean;
Break;

