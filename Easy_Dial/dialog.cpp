#include "dialog.hpp"
// Cost: O(N*log(27)), on 26 es el nombre total de caracters en el alfabet més el '\0', on N és la mida de la cadena d'entrada input.
// Aquesta funció implementa un diàleg utilitzant l'objecte easy_dial. En cada iteració del bucle que recorre la cadena d'entrada input, 
// es realitzen operacions com anterior, seguent, i altres sobre l'objecte easy_dial
// Com que la cadena d'entrada té N caràcters, el cost total és O(N * log(27)), on N és la mida de la cadena d'entrada input i afegir,
// que el log(27), ja que fa ús d'altres funcions de la classe easy_dial amb aquest cost.
void dialog::dialog(easy_dial& easy, const string& input, vector<string>& answers, nat& numtelf) throw(){
    try {
        easy.inici();
        answers.resize(0);
        answers.push_back(easy.inici());
        string nomactual = answers.back(); // Guardamos el nombre actual
        for (nat i = 0; i < input.size(); ++i) {
	    if (input[i] == phone::DELETECHAR){
            	nomactual = easy.anterior();
		answers.push_back(nomactual);

 	    }else if (input[i] == phone::ENDCHAR) {
            	if (answers.size() > 1) {
                	nomactual = easy.seguent(phone::ENDPREF);
                	answers.push_back(nomactual);
            	}
            }else{
                string nounom = easy.seguent(input[i]);
                if (nounom != nomactual) {
                    answers.push_back(nounom);
                    nomactual = nounom;
                }
            }
        }
        numtelf = easy.num_telf();
    } 
    catch (error missatge_error) {
        answers.push_back(missatge_error.mensaje());
        numtelf = 0;
        return;
    }
}
