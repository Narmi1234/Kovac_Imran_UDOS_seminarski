/**********************************************************************************************************************\
Autor: Kovac Imran
Predmet: Uvod u digitalnu obradu slike
Akademska: 2021/2022 godina

Ovaj kod implementira feature matching proizvoljne dvije slike koristeći SIFT detektor i SIFT deskriptor. Preciznije,
korištene su već implementirane funkcije u OpenCV, jer moj pokušaj implementacije ovih funkcija od nule nije bio
potpuno uspješan. Za dobijanja keypoints-a, odnosno tačaka od interesa je korišten SIFT detektor, dok je za deskipciju
pronađenih tačaka korišten SIFT deskriptor. Bitno je naglasiti da je moguće za detekciju tačaka od interesa koristiti i
neki drugi detektor osim SIFT detektora.
***********************************************************************************************************************/
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
  //Mat image = imread("venecija2.jpg");
  //Mat image2 = imread("venecija.jpg");

  Mat image = imread("sarajevo-panorama-1.jfif");
  Mat image2 = imread("vijecnica.png");
  resize(image,image, Size(image.cols * 0.5,image.rows * 0.5),0,0);

  //Mat image = imread("karo_predlozak.png");
  //Mat image = imread("pik_predlozak.png");
  //Mat image2 = imread("karo_r_1.jpg");

  // Kreiranje "smart pointer" za SIFT feature detector.
  Ptr<SIFT> featureDetector = SIFT::create();
  vector<KeyPoint> keypoints;

  // Detekcija keypoint-a
  featureDetector->detect(image, keypoints);

  // Kreiranje "smart pointer-a" za SIFT extractor
  Ptr<SIFT> featureExtractor = SIFT::create();

  // Za svaku keypoint se racuna deskriptor sa 128 elemenata na nacin opisan u izvjestaju
  // Svaki red u matrici "descriptors" odgovara jednoj od keypoint tacaka
  Mat descriptors;
  featureExtractor->compute(image, keypoints, descriptors);

  // Prikaz znacajki
  Mat outputImage;
  drawKeypoints(image, keypoints, outputImage);
  namedWindow("Znacajke na slici 1");
  imshow("Znacajke na slici 1", outputImage);

  // ista procedura i za drugu sliku

  // Kreiranje "smart pointer" za SIFT feature detector
  Ptr<SIFT> featureDetector2 = SIFT::create();
  vector<KeyPoint> keypoints2;

  // Detekcija keypoint-a
  featureDetector2->detect(image2, keypoints2);

  // Kreiranje "smart pointer-a" za SIFT extractor
  Ptr<SIFT> featureExtractor2 = SIFT::create();

  // Za svaku keypoint se racuna deskriptor sa 128 elemenata na nacin opisan u izvjestaju
  // Svaki red u matrici "descriptors" odgovara jednoj od keypoint tacaka
  Mat descriptors2;
  featureExtractor2->compute(image2, keypoints2, descriptors2);

  //Prikaz detektovanih znacajki
  Mat outputImage2;
  drawKeypoints(image2, keypoints2, outputImage2);

  namedWindow("Znacajke na slici 2");
  imshow("Znacajke na slici 2", outputImage2);

  //Matching descriptors
  BFMatcher matcher(NORM_L2);
  vector<DMatch> matches;
  matcher.match(descriptors, descriptors2, matches);

  //Prikaz rezultata matchinga
  namedWindow("Matches", 1);
  Mat image_matches;
  drawMatches(image, keypoints, image2, keypoints2, matches, image_matches);
  imshow("Matches", image_matches);

  while(1){
      char keyPress = waitKey(25);
      if (keyPress == 'q'){
          destroyAllWindows();
          break;
      }
  }

  return 0;

}
