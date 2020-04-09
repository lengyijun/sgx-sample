```
make
./sgx-sample
```


if you meet such problems:

```
./app/app.c:50：对‘OPENSSL_init_crypto’未定义的引用
./libapp.a(sign.o)：在函数‘save_signature’中：
./app/sign.c:76：对‘ECDSA_SIG_set0’未定义的引用
collect2: error: ld returned 1 exit status
Makefile:12: recipe for target 'all' failed
make: *** [all] Error 2
```

you need to install a custom openssl-1.1.1f

and modify the path in `main.go` and `app/makefile`

