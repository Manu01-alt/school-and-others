
unsigned int recursive_sum(unsigned int n) {

    if(n<1) //passo base
        return 0;
    else //passo ricorsivo
        return n+recursive_sum(n-1);


return 0;
}

