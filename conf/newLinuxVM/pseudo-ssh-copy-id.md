
```
cat ~/.ssh/id_rsa.pub | ssh USER@HOST "mkdir -p ~/.ssh && chmod ~/.ssh && cat >> ~/.ssh/authorized_keys"

```
