class Antirimbalzo {
    public:
        Antirimbalzo();
        void Elabora(bool condizioneon);
        unsigned long tPeriodoBlackOut;
        unsigned long tDurataClickLungo;
        void (*cbClickLungo)(); // call back per click > tDurataClickLungo
        void (*cbClickCorto)();
        void (*cbInizioStatoOn)(); // call back per inizio stato on
    private:
        unsigned long tultimocampione;
        unsigned long periodocampionamento;
        unsigned long tInizioStatoOn;
        byte somma;
        byte soglia;
        bool statoOnIniziato;
        
};