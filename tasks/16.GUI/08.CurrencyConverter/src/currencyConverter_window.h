#ifndef CURRENCY_CONVERTER_WINDOW_H
#define CURRENCY_CONVERTER_WINDOW_H

#include "GUI.h"
#include "Graph.h"

enum Currency
{
	CurrencyUSD,
	CurrencyEUR,
	CurrencyBGN
};

struct CurrencyConverter_window : public Graph_lib::Window
{
	CurrencyConverter_window(Point xy, int w, int h, const string& title);
private:
	Graph_lib::Button quit_button;
	Graph_lib::In_box inputBox;
	Graph_lib::Out_box outputBox;

	Graph_lib::Button inputCurrencyButton;
	Graph_lib::Button outputCurrencyButton;
	Graph_lib::Menu inputCurrencyMenu;
	Graph_lib::Menu outputCurrencyMenu;

	Graph_lib::Button convertButton;
	
	Currency inputCurrency;
	Currency outputCurrency;

	// callbacks
	static void cb_inputUsdSelected(Graph_lib::Address callee, Graph_lib::Address pw);
	void inputUsdSelected();
	static void cb_inputEurSelected(Graph_lib::Address callee, Graph_lib::Address pw);
	void inputEurSelected();
	static void cb_inputBgnSelected(Graph_lib::Address callee, Graph_lib::Address pw);
	void inputBgnSelected();
	
	static void cb_outputUsdSelected(Graph_lib::Address callee, Graph_lib::Address pw);
	void outputUsdSelected();
	static void cb_outputEurSelected(Graph_lib::Address callee, Graph_lib::Address pw);
	void outputEurSelected();
	static void cb_outputBgnSelected(Graph_lib::Address callee, Graph_lib::Address pw);
	void outputBgnSelected();
	
	static void cb_showInputCurrencies(Graph_lib::Address callee, Graph_lib::Address pw);
	void showInputCurrencies();
	static void cb_showOutputCurrencies(Graph_lib::Address callee, Graph_lib::Address pw);
	void showOutputCurrencies();
	
	static void cb_convert(Graph_lib::Address callee, Graph_lib::Address pw);
	void convert();
	
	static void cb_quit(Graph_lib::Address callee, Graph_lib::Address pw);
	void quit();
};

#endif // CURRENCY_CONVERTER_WINDOW_H
