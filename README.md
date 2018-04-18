
#include <stdio.h>
#include <fcntl.h> 
#include <io.h>   
#include <string.h>
#include <codecvt> 
#include <fstream>
#include<wchar.h>

using namespace std;

typedef struct SinhVien
{
	wchar_t mssv[20];
	wchar_t hoten[30];
	wchar_t major[30];
	int khoa;
	wchar_t birth[20];
	wchar_t JPG[100];
	wchar_t desc[1000];
	wchar_t hobby[10][200];
	int x;
}SV;
//int demnguoi(FILE* fin)
//{
//	int dem = 0;
//	wchar_t c;
//	while (1) {
//		c = fgetwc(fin);
//		if (c == L'\n')
//			dem++;
//		if (c == 65535)
//			break;
//	}
//	return dem;
//}
void tachkhoahoc(FILE* fin, int &s){
	fseek(fin, 2L, SEEK_CUR);
	fwscanf(fin, L"%d", &s);
	fseek(fin, 1L, SEEK_CUR);
	
}
void tachnoidung(FILE* fin, wchar_t noidung[]){
	int i = 0;
	wchar_t c;
	fseek(fin, 2L, SEEK_CUR);
	while (1){
		c = fgetwc(fin);
		if (c == L'"' || c == L'\n'||c == EOF)
			break;
		else{
			noidung[i] = c;
			i++;
		}
	}
	noidung[i] = '\0';
}
int demsothich(FILE*fin){
	int dem = 0;
	wchar_t c;
	while (1){
		c = fgetwc(fin);
		if (c == L'"')
			dem++;
		if (c == '\n'||c == EOF)
			break;
	}
	return (dem / 2) - 7;
}
void sothichmoinguoi(FILE* fin, SV sv[10])
{
	for (int i = 0; i < 3; i++)
	{
		sv[i].x = demsothich(fin);
	}
	rewind(fin);
}
void GanNoiDung(FILE* fin, SV &sv){
	int i;
	
	tachnoidung(fin, sv.mssv);
	tachnoidung(fin, sv.hoten);
	tachnoidung(fin, sv.major);
	tachkhoahoc(fin, sv.khoa);
	tachnoidung(fin, sv.birth);
	tachnoidung(fin, sv.JPG);
	tachnoidung(fin, sv.desc);
	for (i = 0; i < sv.x; i++){
		tachnoidung(fin, sv.hobby[i]);
	}
}
//wchar_t duongdanhtml(SV sv)
//{
//	wchar_t tenweb[] = L"Websites\\";
//	wchar_t duoifile[50] = L".html";
//	wcscat(tenweb, sv.mssv);
//	wcscat(tenweb, duoifile);
//	return tenweb;
//}
//void xuatnoidungvaohtml(FILE* fDefault,FILE*sinhvien ,SV &sv){
//	wchar_t
//}
void main()
{
	_setmode(_fileno(stdout), _O_U16TEXT); 
	_setmode(_fileno(stdin), _O_U16TEXT);// hien tieng viet tren CMD
	SV sv[20];
	int soSV = 10, k;
	FILE *fin = _wfopen(L"ListSV.csv", L"r, ccs=UTF-8");
	if (!fin)
		wprintf(L"Không thể đọc file \n");
	else{
		sothichmoinguoi(fin, sv);
		fseek(fin, 1L, SEEK_CUR);
		for (k = 0; k < soSV; k++){
			fseek(fin, 1L, SEEK_CUR);
			GanNoiDung(fin, sv[k]);
		}
	}
	fclose(fin);
	//int i = 0;
	//FILE *fDefault = _wfopen(L"Websites\\Default.html", L"r, ccs=UTF-8");
	//if (!fDefault)
	//	wprintf(L"Không thể đọc file \n");
	//else{
	//	while (i < 10){
	//		wchar_t tenweb[50] = duongdanhtml(sv[i]);
	//		FILE *fweb = _wfopen(tenweb, L"w, ccs=UTF-8");
	//		if (!fDefault)
	//			wprintf(L"Không thể mở file \n");

	//	}
	//
	//}
}
