#include "currencyConverter_window.h"

using namespace Graph_lib;

#define USD_COEFF (1.5)
#define EUR_COEFF (2)
#define BGN_COEFF (1)

double GetCurrencyCoefficient(Currency c)
{
	if (c == CurrencyUSD) return USD_COEFF;
	else if (c == CurrencyEUR) return EUR_COEFF;
	else if (c == CurrencyBGN) return BGN_COEFF;
	else return 0;
}

CurrencyConverter_window::CurrencyConverter_window(Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title),
	  inputBox(Point(x_max() - 410, 100), 100, 20, ""),
	  outputBox(Point(x_max() - 210, 100), 100, 20, ""),
	  
	  inputCurrencyButton(Point(x_max() - 500, 100), 70, 20, "USD", cb_showInputCurrencies),
	  outputCurrencyButton(Point(x_max() - 300, 100), 70, 20, "USD", cb_showOutputCurrencies),
	  convertButton(Point(x_max() - 350, 130), 70, 20, "Convert", cb_convert),
	  
	  inputCurrencyMenu(Point(x_max() - 500, 100), 70, 20, Menu::vertical, "Input currencies"),
	  outputCurrencyMenu(Point(x_max() - 300, 100), 70, 20, Menu::vertical, "Output currencies"),
	  
	  quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit)
{
	inputCurrencyMenu.attach(new Button(Point(0, 0), 70, 20, "USD", cb_inputUsdSelected));
	inputCurrencyMenu.attach(new Button(Point(0, 0), 70, 20, "EUR", cb_inputEurSelected));
	inputCurrencyMenu.attach(new Button(Point(0, 0), 70, 20, "BGN", cb_inputBgnSelected));

	outputCurrencyMenu.attach(new Button(Point(0, 0), 70, 20, "USD", cb_outputUsdSelected));
	outputCurrencyMenu.attach(new Button(Point(0, 0), 70, 20, "EUR", cb_outputEurSelected));
	outputCurrencyMenu.attach(new Button(Point(0, 0), 70, 20, "BGN", cb_outputBgnSelected));
	
	attach(inputBox);
	attach(outputBox);
	
	attach(inputCurrencyButton);
	attach(outputCurrencyButton);
	attach(convertButton);
	
	attach(inputCurrencyMenu);
	attach(outputCurrencyMenu);
	
	attach(quit_button);
	
	inputCurrencyMenu.hide();
	outputCurrencyMenu.hide();
};

void CurrencyConverter_window::cb_inputUsdSelected(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CurrencyConverter_window>(pw).inputUsdSelected();
}
	
void CurrencyConverter_window::inputUsdSelected()
{
	this->inputCurrency = CurrencyUSD;
	this->inputCurrencyButton.label = "USD";

	this->inputCurrencyMenu.hide();
	this->inputCurrencyButton.show();
}

void CurrencyConverter_window::cb_inputEurSelected(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CurrencyConverter_window>(pw).inputEurSelected();
}
	
void CurrencyConverter_window::inputEurSelected()
{
	this->inputCurrency = CurrencyEUR;
	this->inputCurrencyButton.label = "EUR";

	this->inputCurrencyMenu.hide();
	this->inputCurrencyButton.show();
}

void CurrencyConverter_window::cb_inputBgnSelected(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CurrencyConverter_window>(pw).inputBgnSelected();
}
	
void CurrencyConverter_window::inputBgnSelected()
{
	this->inputCurrency = CurrencyBGN;
	this->inputCurrencyButton.label = "BGN";

	this->inputCurrencyMenu.hide();
	this->inputCurrencyButton.show();
}

void CurrencyConverter_window::cb_outputUsdSelected(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CurrencyConverter_window>(pw).outputUsdSelected();
}
	
void CurrencyConverter_window::outputUsdSelected()
{
	this->outputCurrency = CurrencyUSD;
	this->outputCurrencyButton.label = "USD";

	this->outputCurrencyMenu.hide();
	this->outputCurrencyButton.show();
}

void CurrencyConverter_window::cb_outputEurSelected(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CurrencyConverter_window>(pw).outputEurSelected();
}
	
void CurrencyConverter_window::outputEurSelected()
{
	this->outputCurrency = CurrencyEUR;
	this->outputCurrencyButton.label = "EUR";

	this->outputCurrencyMenu.hide();
	this->outputCurrencyButton.show();
}

void CurrencyConverter_window::cb_outputBgnSelected(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CurrencyConverter_window>(pw).outputBgnSelected();
}
	
void CurrencyConverter_window::outputBgnSelected()
{
	this->outputCurrency = CurrencyBGN;
	this->outputCurrencyButton.label = "BGN";

	this->outputCurrencyMenu.hide();
	this->outputCurrencyButton.show();
}

void CurrencyConverter_window::cb_showInputCurrencies(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CurrencyConverter_window>(pw).showInputCurrencies();
}

void CurrencyConverter_window::showInputCurrencies()
{
	this->inputCurrencyButton.hide();
	this->inputCurrencyMenu.show();
}

void CurrencyConverter_window::cb_showOutputCurrencies(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CurrencyConverter_window>(pw).showOutputCurrencies();
}

void CurrencyConverter_window::showOutputCurrencies()
{
	this->outputCurrencyButton.hide();
	this->outputCurrencyMenu.show();
}

void CurrencyConverter_window::cb_convert(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CurrencyConverter_window>(pw).convert();
}

void CurrencyConverter_window::convert()
{
	double inputNumber = (double)this->inputBox.get_int();
	
	double inputCurrencyCoeff = GetCurrencyCoefficient(this->inputCurrency);	
	double outputCurrencyCoeff = GetCurrencyCoefficient(this->outputCurrency);	

	double result = (inputNumber * inputCurrencyCoeff) / outputCurrencyCoeff;

	this->outputBox.put(std::to_string(result));
}

void CurrencyConverter_window::cb_quit(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CurrencyConverter_window>(pw).quit();
}

void CurrencyConverter_window::quit()
{
	hide();
}
