#ifndef METRICS_H
#define METRICS_H

#define SCREEN_WIDTH (1200)
#define SCREEN_HEIGHT (900)
#define SCREEN_TITLE ("File diagram")

#define RECTS_WIDTH (200)
#define RECTS_HEIGHT (75)

#define FLTK_HEADERS_CNT (3)
#define FLTK_HEADERS_X (600)
#define FLTK_HEADERS_Y (50)
#define FLTK_HEADERS_TITLE ("")
#define FLTK_HEADERS_CONTENT ("FLTK headers")

#define FLTK_CODE_CNT (3)
#define FLTK_CODE_X (FLTK_HEADERS_X + RECTS_WIDTH + (RECTS_WIDTH / 2))
#define FLTK_CODE_Y (FLTK_HEADERS_Y + (2 * RECTS_HEIGHT))
#define FLTK_CODE_TITLE ("")
#define FLTK_CODE_CONTENT ("FLTK code")

#define WINDOW_H_CNT (1)
#define WINDOW_H_X (FLTK_HEADERS_X - (RECTS_WIDTH / 5))
#define WINDOW_H_Y (FLTK_HEADERS_Y + (RECTS_HEIGHT * 3))
#define WINDOW_H_TITLE ("Window.h:")
#define WINDOW_H_CONTENT ("// window interface")

#define POINT_H_CNT (1)
#define POINT_H_X (FLTK_HEADERS_X - (2 * RECTS_WIDTH))
#define POINT_H_Y (FLTK_HEADERS_Y + RECTS_HEIGHT)
#define POINT_H_TITLE ("Point.h:")
#define POINT_H_CONTENT ("struct Point {...};")

#define GRAPH_H_CNT (1)
#define GRAPH_H_X (FLTK_HEADERS_X - (2 * RECTS_WIDTH))
#define GRAPH_H_Y (FLTK_HEADERS_Y + (RECTS_HEIGHT * 4))
#define GRAPH_H_TITLE ("Graph.h:")
#define GRAPH_H_CONTENT ("// graphing interface")

#define WINDOW_CPP_CNT (1)
#define WINDOW_CPP_X (FLTK_HEADERS_X - (RECTS_WIDTH / 2))
#define WINDOW_CPP_Y (FLTK_HEADERS_Y + (RECTS_HEIGHT * 6))
#define WINDOW_CPP_TITLE ("window.cpp:")
#define WINDOW_CPP_CONTENT ("Window code")

#define GUI_H_CNT (1)
#define GUI_H_X (FLTK_HEADERS_X + (RECTS_WIDTH * 1.5))
#define GUI_H_Y (FLTK_HEADERS_Y + (RECTS_HEIGHT * 5))
#define GUI_H_TITLE ("GUI.h:")
#define GUI_H_CONTENT ("// GUI interface")

#define GRAPH_CPP_CNT (1)
#define GRAPH_CPP_X (FLTK_HEADERS_X - (RECTS_WIDTH * 2.5))
#define GRAPH_CPP_Y (FLTK_HEADERS_Y + (RECTS_HEIGHT * 7))
#define GRAPH_CPP_TITLE ("Graph.cpp:")
#define GRAPH_CPP_CONTENT ("Graph code")

#define SIMPLE_WINDOW_H_CNT (1)
#define SIMPLE_WINDOW_H_X (FLTK_HEADERS_X + (RECTS_WIDTH / 4))
#define SIMPLE_WINDOW_H_Y (FLTK_HEADERS_Y + (RECTS_HEIGHT * 7.5))
#define SIMPLE_WINDOW_H_TITLE ("Simple_window.h:")
#define SIMPLE_WINDOW_H_CONTENT ("window interface")

#define GUI_CPP_CNT (1)
#define GUI_CPP_X (FLTK_HEADERS_X + (RECTS_WIDTH * 1.8))
#define GUI_CPP_Y (FLTK_HEADERS_Y + (RECTS_HEIGHT * 7))
#define GUI_CPP_TITLE ("GUI.cpp:")
#define GUI_CPP_CONTENT ("GUI code")

#define CHAPTER_12_CPP_CNT (1)
#define CHAPTER_12_CPP_X (FLTK_HEADERS_X - RECTS_WIDTH)
#define CHAPTER_12_CPP_Y (FLTK_HEADERS_Y + (RECTS_HEIGHT * 9.5))
#define CHAPTER_12_CPP_TITLE ("chapter12.cpp:")
#define CHAPTER_12_CPP_CONTENT ("int main() {...}")

#define RECTS_CNT (FLTK_HEADERS_CNT + \
				   FLTK_CODE_CNT + \
				   WINDOW_H_CNT + \
				   POINT_H_CNT + \
				   GRAPH_H_CNT + \
				   WINDOW_CPP_CNT + \
				   GUI_H_CNT + \
				   GRAPH_CPP_CNT + \
				   SIMPLE_WINDOW_H_CNT + \
				   GUI_CPP_CNT + \
				   CHAPTER_12_CPP_CNT)

#endif // METRICS_H
