void Resize(int w, int h);
void MouseMotion(int x, int y);
void initialiseWindow(int argc,char **argv);
void MenuWindow();
void LevelWindow(int levelSelected);
void LevelSelectWindow();

extern float square_pos_x;
extern float square_pos_y;
extern int desc;
extern bool g_lmb;
extern float g_lmb_pos_x;
extern float g_lmb_pos_y;