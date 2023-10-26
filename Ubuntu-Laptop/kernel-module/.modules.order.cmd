cmd_/home/srikanth/Downloads/kernel-module/modules.order := {   echo /home/srikanth/Downloads/kernel-module/hello.ko; :; } | awk '!x[$$0]++' - > /home/srikanth/Downloads/kernel-module/modules.order
