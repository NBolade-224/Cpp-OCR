#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

string ReadImage(string imgToRead)
{
    string outText;
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    Pix *image = pixRead(imgToRead.c_str());
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText.c_str());

    // Destroy used object and release memory
    api->End();
    delete api;
    pixDestroy(&image);

    return outText;
}

int main()
{
    return 0;
}