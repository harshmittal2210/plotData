Check active connection at port in windows:

```
$ netstat -ano|findstr 65040
```

Clode that port:

```
taskkill /F /PID <task id>
```