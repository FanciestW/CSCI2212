//==============================================================================
//  The Mc-Sixties Menu
//
#include "tools.hpp"

class MenuItem {
  private:
	float price; 
	string product;
  public:
    //----------------------------------------------------------------------
    // This code does not check for runtime read errors.
    MenuItem( istream& in ){
        in >> price ;
        getline(in, product );
    }
    //----------------------------------------------------------------------
    float getPrice(){ return price;}
    //----------------------------------------------------------------------
    void print( ostream& out ){
        out <<setw(20) <<product <<setw(7) <<fixed <<setprecision(2) << price ;
    }
};
ostream& operator << (ostream& out, MenuItem& m ){ m.print(out); return out; }

//==============================================================================
class MenuType {
  private:
	vector<MenuItem> menu;

  public:
    //----------------------------------------------------------------------
    MenuType( istream& instr ){
        for (;;) {
            MenuItem it( instr );
            if ( instr.eof()) break;
            menu.push_back( it );
        }
    }

    //----------------------------------------------------------------------
    void print( ostream& out ){
        int n = menu.size();
        for( int k=0; k<n; ++k ) out << setw(2) <<k <<"  " << menu[k] <<endl;
    }
    //----------------------------------------------------------------------
    MenuItem operator[] ( int k ){ return menu[k]; }
};
ostream& operator << (ostream& out,  MenuType& m ){ m.print(out); return out; }

//------------------------------------------------------------------------------
int main ( void ) {
    int order;      // The customer's selection from the menu.

    ifstream menuData ( "mcmenu.txt" );
    if (! menuData ) fatal( "Could not open mcmenu.txt for reading.");

    puts( "\nWelcome to Mc-Sixties \n" );
    MenuType menu( menuData );
    menu.print( cout );
    cout << "\nWhat would you like to order? " ;
    cin >> order;

    cout << "That will be " << menu[order].getPrice()
         << "\nOver one million orders sold!\n\n" ;
    return 0;
}


/* Output: ---------------------------------------------------------------------
Welcome to Mc-Sixties 

 0               End order   0.00
 1               Hamburger   0.59
 2            Cheeseburger   0.69
 3        Double hamburger   0.89
 4     Double cheeseburger   0.99
 5                   Combo   1.30
 6            Double combo   1.60
 7                   Shake   0.59
 8                    Coke   0.29

What would you like to order? 1
That will be 0.59
Over one million orders sold!
*/