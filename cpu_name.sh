cat /proc/cpuinfo | grep 'model name' | head -n 1 | awk '{for(i=4;i<13;i++){printf "%s ",$i}printf"\n"}'