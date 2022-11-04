# SSH info

## AWS
### Creating an rsa key

In AWS when creating a key pair, I just download the the openssh pem file. It is the ssh private key.
There is no way to download it later again.

```
cp aws_rsa.pem ~/.ssh/aws_rsa
chmod 400 ~/.ssh/aws_rsa

# OR

vim ~/.ssh/aws_rsa
#paste content of aws_rsa.pem

chmod 400 ~/.ssh/aws_rsa
```

### setup .ssh/authorized_keys
add my public key to the aws host
```
scp -i  ~/.ssh/aws_rsa ~/.ssh/id_rsa.pub ssh ubuntu@44.204.176.142:/home/ubuntu

ssh ubuntu@44.204.176.142
cat id_rsa.pub >> .ssh/authorized_keys

```
.ssh/authorized_keys

## To generate public key from private key
ssh-keygen -f ~/.ssh/aws_rsa -y > ~/.ssh/aws_rsa.pub

## adding my public key to remote host when user/password is available

```
ssh-copy-id -i id_rsa.pub user@host
```

it will require to type in the password