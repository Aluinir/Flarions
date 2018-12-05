{
    std::vector<double> puntix;
    std::vector<double> puntiy;
    int puntiin = 9;
    int iniziox[9] = {100,000,000,100,200,300,300,200,100};
    int inizioy[9] = {000,100,200,300,300,200,100,000,000};
    int maxv[12]    = {0,1,2,3,4,5,6,7,8,9,10,11};
    int max;
    int j = 0;
    int nx = 4;
    int ny = 3;
    TCanvas *imm = new TCanvas("Flarions","",1400,1000);
    imm -> Divide(nx,ny,0,0);
    TGraph **grafico = new TGraph*[12]; 
    for (int k=1;k<=(nx*ny);k++){
        grafico[k-1]= new TGraph();
        max = maxv[k-1];
        for (int i=0;i<puntiin;i++){
            puntix.push_back(iniziox[i]);
            puntiy.push_back(inizioy[i]);
        }
        for (int n=1;n<=max;n++){
            for (int i=1;i<=(puntiin-1)*pow(2,n-1);i++){
                j=2*(i-1);
                if ((i)%2==1) {
                    if (puntix[j]==puntix[j+1]&&puntiy[j]<puntiy[j+1]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]-((puntiy[j+1]-puntiy[j])/2)));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]+((puntiy[j+1]-puntiy[j])/2)));
                        
                    }
                    else if (puntix[j]==puntix[j+1]&&puntiy[j]>puntiy[j+1]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]+((puntiy[j]-puntiy[j+1])/2)));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]-((puntiy[j]-puntiy[j+1])/2)));
                        
                    }
                    else if (puntiy[j]==puntiy[j+1]&&puntix[j]<puntix[j+1]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]+((puntix[j+1]-puntix[j])/2)));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]+((puntix[j+1]-puntix[j])/1)));
                    }
                    else if (puntiy[j]==puntiy[j+1]&&puntix[j]>puntix[j+1]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]-((puntix[j]-puntix[j+1])/2)));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]-((puntix[j]-puntix[j+1])/1)));
                    }
                    else if (puntiy[j+1]>puntiy[j]&&puntix[j+1]>puntix[j]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j+1]));
                    }
                    else if (puntiy[j+1]>puntiy[j]&&puntix[j+1]<puntix[j]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j+1]));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]));
                    }
                    else if (puntiy[j+1]<puntiy[j]&&puntix[j+1]>puntix[j]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j+1]));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]));
                    }
                    else if (puntiy[j+1]<puntiy[j]&&puntix[j+1]<puntix[j]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j+1]));
                    }
                }
                else {
                    if (puntix[j]==puntix[j+1]&&puntiy[j]<puntiy[j+1]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]+((puntiy[j+1]-puntiy[j])/2)));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]+((puntiy[j+1]-puntiy[j])/2)));
                        
                    }
                    else if (puntix[j]==puntix[j+1]&&puntiy[j]>puntiy[j+1]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]-((puntiy[j]-puntiy[j+1])/2)));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]-((puntiy[j]-puntiy[j+1])/2)));
                        
                    }
                    else if (puntiy[j]==puntiy[j+1]&&puntix[j]<puntix[j+1]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]+((puntix[j+1]-puntix[j])/2)));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]-((puntix[j+1]-puntix[j])/1)));
                    }
                    else if (puntiy[j]==puntiy[j+1]&&puntix[j]>puntix[j+1]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]-((puntix[j]-puntix[j+1])/2)));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]+((puntix[j]-puntix[j+1])/1)));
                    }
                    else if (puntiy[j+1]>puntiy[j]&&puntix[j+1]>puntix[j]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j+1]));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]));
                    }
                    else if (puntiy[j+1]>puntiy[j]&&puntix[j+1]<puntix[j]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j+1]));
                    }
                    else if (puntiy[j+1]<puntiy[j]&&puntix[j+1]>puntix[j]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j]));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j+1]));
                    }
                    else if (puntiy[j+1]<puntiy[j]&&puntix[j+1]<puntix[j]){
                        puntix.insert(puntix.begin()+(j+1),(puntix[j+1]));
                        puntiy.insert(puntiy.begin()+(j+1),(puntiy[j]));
                    }            
                }
            }
        }
        for (int i=0;i<=((puntiin-1)*pow(2,max));i++){
            grafico[k-1] -> SetPoint(i,puntix[i],puntiy[i]);
        }
        imm -> cd(k) -> SetMargin(0.1,0.1,0.1,0.1);
        grafico[k-1] -> Draw();
        puntix.clear();
        puntiy.clear();        
    }
}
