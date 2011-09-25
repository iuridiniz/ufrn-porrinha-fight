int num_jogadores () {
    
    int num=0;
    
    do {

	tela_num_jogadores(&num);
	
    } while (num < 1 || num > 3);
    ;;
    
    return(num);
}    

