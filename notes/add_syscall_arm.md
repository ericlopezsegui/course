# Afegint una crida a sistema a arquitectures ARM

## Objectiu
En aquest laboratori
crearem una crida a
sistema anomenada
getdummymul que donats
dos números enters en
mode usuari els passarà a
mode nucli i els multiplicarà
en el nucli. Un cop acabada
l’operació, ens retornarà el
seu resultat en mode
usuari.

## Requeriments

* Tenir el kernel de linux compilat.
* Utilizarem el kernel 5.15.19 en aquesta demostració.

## Pas 1. Actualitzant la taula de crides al sistema

Afegiu una nova crida sistema identificat pel següent enter disponible. Assumirem que el
següent enter és el 448. Definirem el 449:

```sh
# Aneu a la carpeta del kernel de linux
vim /arch/arm/tools/syscall.tbl

# Afegiu el contingut següent
# Final del fitxer _> al final de common
449 common getdummymul sys_getdummymul
```

```sh
vim /root/linux-5.15.19/include/linux/syscalls.h
# Afegir al final:
````

```c
asmlinkage long sys_getdummymul(int num1, int num2, int* resultat);
```

## Pas 2. Implementació de la crida a sistema

```sh
vim kernel/sys.c
# Afegir al final:
````

```c
SYSCALL_DEFINE3(getdummymul,int, num1, int ,num2, int*, resultat){
    int res = num1 * num2;
    copy_to_user(resultat, &res, sizeof(int));
    return 0;
}
```

### Pas 3. Matching amb unistd.h

```sh
vim include/uapi/asm-generic/unistd.h
```
```c
//Editeu la línia augmentant en 1 el valor que tingueu. En el meu cas 449 -> 450:
#define __NR_syscalls 450
//Just damunt de la línia anterior -> afegim:
#define __NR_getdummymul 449
__SYSCALL(__NR_getdummymul, sys_getdummymul)
```
## Recompilar el kernel

```sh
make -j `nproc` && make modules_install -j `nproc` && make install -j `nproc`
reboot
```
