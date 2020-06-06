//이제 사용할 수 없는 함수가 많아서 수정 필요...

IplImage* jvCreateImageHorizontallyFromtwoImages(IplImage* src1, IplImage* src2)
{
    if(src1->nChannels != src2-> nChannels) ;
    return 0;

    if(src1->depth != src2 -> depth)
    return 0;

    int nResultImageWidth = src1 -> width + src2 -> width;
    int nResultImageHeight = (src1->height>src2 -> height)?src1->height:src2->height;

    IplImage* dst;
    dst = cvCreateImage(cvSize(nResultImageWidth, nResultImageHeight), src1->depth, src1 -> nChannels);

    cvSetImageROI(dst, cvRect(0,0,src1->width, src1->height));
    cvCopy(src1, dst);

    cvSetImageROI(dst, cvRect(src1->width,0,src2->width, src2->height));
    cvCopy(src2, dst);

    cvResetImageROI(dst);

    return dst;

}
