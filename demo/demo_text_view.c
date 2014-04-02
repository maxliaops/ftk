#include "ftk.h"
#include <assert.h>

FtkWidget* text_view1  = NULL;

static Ret button_quit_clicked(void* ctx, void* obj)
{
	ftk_widget_unref(ctx);

	return RET_OK;
}

static Ret scroll_bar_on_scroll(void* ctx, void* scroll_bar)
{
	static int old_at_line = 0;

	int total_lines = ftk_text_view_get_total_lines(text_view1);
	int per = ftk_scroll_bar_get_value(scroll_bar);
	int at_line = total_lines * per / 100;

	if (0 == old_at_line) old_at_line = total_lines;

	int offset = at_line - old_at_line;

	ftk_text_view_v_move_caret(text_view1, offset);

	printf("%s: value=%d, totals = %d, offset = %d\n", __func__, per, total_lines, offset);

	old_at_line = at_line;
	return RET_OK;
}

#define XX_STR  "hahah\n4\n5\n latst"

#define TEXT_STR "libpng is the official PNG reference library. It supports almost all PNG features, is extensible, and has been extensively tested for over 15 years. The home site for development versions (i.e., may be buggy or subject to change or include experimental features) is http://libpng.sourceforge.net/, and the place to go for questions about the library is the png-mng-implement mailing list.\n\nlibpng is available as ANSI C (C89) source code and requires zlib 1.0.4 or later (1.2.3 or later recommended for performance and security reasons). The current public release, libpng 1.4.3, contains fixes for two potential security issues: "

#define TEXT1_STR "Several versions of libpng through 1.4.2 (and through 1.2.43 in the older series) contain a bug whereby progressive applications such as web browsers (or the rpng2 demo app included in libpng) could receive an extra row of image data beyond the height reported in the header, potentially leading to an out-of-bounds write to memory (depending on how the application is written) and the possibility of execution of an attacker's code with the privileges of the libpng user (including remote compromise in the case of a libpng-based browser visiting a hostile web site). This vulnerability has been assigned ID CVE-2010-1205 (via Mozilla). \n\n4\n5\n6\n7\n8\nlast line"

#ifdef FTK_AS_PLUGIN
#include "ftk_app_demo.h"
FTK_HIDE int FTK_MAIN(int argc, char* argv[]);
FtkApp* ftk_app_demo_text_view_create()
{
	return ftk_app_demo_create(_("text_view"), ftk_main);
}
#else
#define FTK_HIDE extern
#endif /*FTK_AS_PLUGIN*/
FTK_HIDE int FTK_MAIN(int argc, char* argv[])
{
	int width = 0;
	int height = 0;
	FtkWidget* win = NULL;
	FtkWidget* button = NULL;
	FtkWidget* text_view  = NULL;
	FtkWidget* scroll_bar = NULL;

	FTK_INIT(argc, argv);

	win = ftk_app_window_create();
	width = ftk_widget_width(win);
	height = ftk_widget_height(win);
	
	text_view1 = ftk_text_view_create(win, 10, 10, ftk_widget_width(win) - 40, height/3);
	ftk_widget_set_text(text_view1, XX_STR);
	ftk_text_view_set_readonly(text_view1, 1);


	scroll_bar = ftk_scroll_bar_create(win, width-30, 10, 20, height/3);
	ftk_scroll_bar_set_param(scroll_bar, 0, 120, 20);	
	ftk_scroll_bar_set_listener(scroll_bar, scroll_bar_on_scroll, NULL);
	ftk_scroll_bar_set_value(scroll_bar, 100);


	text_view = ftk_text_view_create(win, 10, 15 + height/3, ftk_widget_width(win) - 20, height/3);
	ftk_widget_set_text(text_view, TEXT_STR);
	assert(strcmp(TEXT_STR, ftk_widget_get_text(text_view)) == 0);
	ftk_text_view_set_readonly(text_view, 1);

	button = ftk_button_create(win, width/4, 3*height/4, width/2, 60);
	ftk_widget_set_text(button, "quit");
	ftk_button_set_clicked_listener(button, button_quit_clicked, win);
	ftk_window_set_focus(win, button);

	ftk_widget_set_text(win, "text_view demo");
	ftk_widget_show_all(win, 1);
	FTK_QUIT_WHEN_WIDGET_CLOSE(win);

	FTK_RUN();

	return 0;
}

