
# extend fs on lv

https://www.unixarena.com/2022/01/how-to-extend-the-root-filesystem-in-rhel-8-centos-8.html/

 yum install cloud-utils-growpart -y

## resize partition to max size (-N = dry-run)


growpart /dev/sda 2 -N

growpart /dev/sda 2
pvresize /dev/sda2
lvextend -l +100%FREE /dev/almalinux/home
xfs_growfs /home/

## physical volume
pvs

## volume group
vgs
vgdisplay

## logical volume
lvs
lvextend -l +100%FREE /dev/almalinux/home

# other
## resize partition with parted
https://docs.redhat.com/en/documentation/red_hat_enterprise_linux/8/html/managing_storage_devices/getting-started-with-partitions_managing-storage-devices#proc_resizing-a-partition-with-parted_getting-started-with-partitions

resize partition
