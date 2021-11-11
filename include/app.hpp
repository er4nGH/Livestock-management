#ifndef APP_IG
#define APP_IG


class App
{
    public:
        App();
        void splashScreen();
        int exec();
        void getInformation();
        void print();
        void checkInputs() const;
    private:
        unsigned int cows;
        unsigned int sheep;
        unsigned int chickens;
        
};

#endif
