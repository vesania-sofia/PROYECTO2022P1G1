#include<string>

#ifndef CLSBANCOS_H
#define CLSBANCOS_H

using std::string;
class ClsBancos
{
   public:


        ClsBancos( string = "", int = 0, string = "", int = 0,  string = "");
        mAgregarBanco();
        mIngresarBanco();
        mMenuBancos();


        void mestablecerNombreBanco( string) ;
        string mobtenerNombre() const;


        void mestablecerNumeroCuenta( int );
        int mobtenerNumero() const;


        void mestablecerNombreUsuario ( string );
        string mobtenerUsuario() const;

        void mestablecerSaldoCuenta( int );
        int mobtenerSaldo() const;

        void mestablecerTipoCuenta ( string );
        string mobtenerTipo() const;

        mDespliegueBanco();
        modify();
        searchB();
        deletB();
        virtual ~ClsBancos();

    protected:

    private:


        char m_sNombreBanco[20];
        int m_iNumeroCuenta;
        char m_sNombreUsuario[20];
        int m_iSaldoCuenta;
        char m_sTipoCuenta[20];

};
#endif // CLSBANCOS_H
