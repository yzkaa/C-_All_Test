#include "utils.h"
Utils::Utils()
{

}

bool sortByY(const QPointF &p1, const QPointF &p2)

{
    return p1.y() < p2.y();//升序排列
}

void Utils::Filter(QList<QPointF> &pointList)
{
    QList<QPointF> fittedResult;
    QList<QPointF> fittedAndSmoothResult;
    fittedResult.clear();
    //线性五点拟合去差值
    double tmpY;
    double flag=0;
    if(pointList.size()>=5){
        int N_1 = pointList.size();
        std::vector<QPointF> tmpData(5);
        for(int i=0;i<N_1-5;i++){
            tmpData.clear();
            for(int j=i;j<i+5;j++){
                tmpData.push_back(pointList[j]);
            }
            std::sort(tmpData.begin(),tmpData.end(),sortByY);   //升序排列
            tmpY = (tmpData[1].y()+tmpData[2].y()+tmpData[3].y())/3;
            fittedResult.push_back(QPointF(pointList[i].x(),tmpY));
        }
        fittedResult[fittedResult.size()-1].setX(pointList[pointList.size()-1].x());
    }
    //线性五点平滑
    int N_2 = fittedResult.size();
    tmpY = (3.0*fittedResult[0].y()+2.0*fittedResult[1].y()+fittedResult[2].y()-fittedResult[4].y()) / 5.0;
    if(tmpY<=0){
        tmpY = 0;
    }
    fittedAndSmoothResult.push_back(QPointF(fittedResult[0].x(), tmpY));
    tmpY = (4.0 * fittedResult[0].y() + 3.0 * fittedResult[1].y() + 2 * fittedResult[2].y() + fittedResult[3].y()) / 10.0;
    fittedAndSmoothResult.push_back(QPointF(fittedResult[1].x(), tmpY));
    for(int i=2;i<N_2 - 3;i++){
        tmpY = (fittedResult[i - 2].y() + fittedResult[i - 1].y() + fittedResult[i].y() + fittedResult[i + 1].y() + fittedResult[i + 2].y()) / 5.0;
        fittedAndSmoothResult.push_back(QPointF(fittedResult[i].x(), tmpY));
    }
    tmpY = (4.0 * fittedResult[N_2 - 1].y() + 3.0 * fittedResult[N_2 - 2].y() + 2 * fittedResult[N_2 - 3].y() + fittedResult[N_2 - 4].y()) / 10.0;
    fittedAndSmoothResult.push_back(QPointF(fittedResult[N_2 - 2].x(), tmpY));
    tmpY  = (3.0 * fittedResult[N_2 - 1].y() + 2.0 * fittedResult[N_2 - 2].y() + fittedResult[N_2 - 3].y() - fittedResult[N_2 - 5].y()) / 5.0;
    fittedAndSmoothResult.push_back(QPointF(fittedResult[N_2 - 1].x(), tmpY));

    pointList.clear();
    pointList = fittedAndSmoothResult;
}

void Utils::tipMessageBox(QString Info)
{
    if(Info.isEmpty())
    {
        return;
    }
    QMessageBox Tip;
    Tip.setText(Info);
    Tip.exec();
}

void Utils::peakParameterCalculation(QList<QPointF> &currentData, double &FWHM, double &Area)
{

    //取得最大最小值
    //STL风格遍历
    int index = 0;
    int currentMaxValue = 0;
    int currentMinValue = 0;
    int currentmaxIndex = 0;
    QList<QPointF>::const_iterator temp;
    for(temp = currentData.begin(); temp != currentData.end(); temp++,index++)
    {
        QPointF point  = *temp;
        if(point.y() > currentMaxValue)
        {
            currentMaxValue = point.y();
            currentmaxIndex = index;
        }
        if(point.y() < currentMinValue)
        {
            currentMinValue = point.y();
        }
    }

    double mingap;
    mingap = (currentMaxValue - currentMinValue) / 28;


    ////峰参数
    //未来5点趋势(斜率值) 数组 Km
    QList<QVector<double>> AmplitudeTrand;
    QVector<double> Km;
    QVector<double> point5;
    double sum = 0;
    double y1,y2,x1,x2;
    for(int i = 0, n = 1; i + n <currentData.size(); n++)
    {
        y2 = currentData.at(i + n).y();
        y1 = currentData.at(i).y();
        x2 = currentData.at(i + n).x();
        x1 = currentData.at(i).x();
        point5 += (y2 - y1) / (x2 - x1);
        sum += (y2 - y1) / (x2 - x1);
        if(n > 5)
        {
            //每个点与之后5个点的斜率，打包
            AmplitudeTrand.push_back(point5);    //再进一级，用at直接对QVector赋值会出错,原理未知，所以采用新的QVector,用append
            sum = sum / 5;
            Km.push_back(sum);
            sum = 0;
            point5.clear();
            n = 1;
            i++;
        }
    }

    //条件：K0  和  Ks 需要总结
    //趋势数组trand
    int up = 0, down = 0;
    double k0 = 0.5, Ks = 8;
    QVector<int> trand;
    for(int i = 0; i < AmplitudeTrand.size(); i++)
    {
        up = 0;
        down = 0;
        //其值与K0对比，判断上升下降趋势
        for(int j = 0; j<AmplitudeTrand.at(i).size(); j++)
        {
            if(AmplitudeTrand.at(i).at(j) > k0)
                up++;
            else if(AmplitudeTrand.at(i).at(j) < -k0)
                down++;
        }
        // 1 上升  -1下降   0抖动或平缓
        if(up >= 3)
            trand += 1;
        else if(down >= 3)
            trand += -1;
        else
            trand += 0;
    }


    //峰起点终点初始别
    //mingap是显示的刻度最小一格的刻度
    //起始点
    //ks总结得出限度
    //起点条件：5点平均趋势Km大于设定好的Ks，处于上升区段的第一点，（由于第一个条件或方式没处理好，要加上第三个条件两点幅值相差最小显示）
    int startflag, endflag, i2;
    QVector<int> startIndex;
    QVector<int> endIndex;
    for(int i = 0; i < trand.size();i++)
    {
        if(trand.at(i) == 1)
        {
            startflag = 0;
            for(i2 = i; i2 < trand.size() && i2 < Km.size(); i2++)
            {
                if(trand.at(i2) == 1)
                {
                    if(Km.at(i2) > Ks && startflag == 0 && currentData.at(i2).y() - currentData.at(i).y() > mingap)
                    {
                        startIndex += i;
                        startflag = 1;
                    }
                }
                else
                        break;
            }
            i=i2;
        }
    }
    //终点
    for(int i = 0; i < trand.size(); i++)
    {
        if(trand.at(i) == -1)
        {
            endflag = 0;
            for(i2 = i; i2 < trand.size() && i2 < Km.size(); i2++)
            {
                if(trand.at(i2) == -1)
                {
                    if(Km.at(i2) > -Ks/2 && endflag == 0 && currentData.at(i).y() - currentData.at(i2).y() > mingap)
                    {
                        endIndex += i2;
                        endflag = 1;
                    }
                }
                else
                        break;
            }
            i = i2;
        }
    }



    //总共的起点终点，单峰多峰情况
    QVector<int> startpointIndex;
    QVector<int> endpointIndex;
    startpointIndex.append(startIndex);
    endpointIndex.append(endIndex);

    //最终起点终点分析
    //前肩峰，寄生峰分析
    QVector<int> addstartIndex;
    QVector<int> addendIndex;
    if(startIndex.size()>1){
        for(int i = 1; i<startIndex.size(); i++)
        {
            down = 0;
            for(i2 = startIndex.at(i - 1); ; i2++)
            {
                if(trand.at(i2) == -1)
                {
                    down = 1;
                    if(endIndex.contains(i2))
                        break;//无前肩峰，与未识别的寄生峰
                }

                else if(i2 == startIndex.at(i) && down ==1 )
                {  //有未被识别的前寄生峰,录入寄生峰数组
                    addstartIndex += startIndex.at(i-1);
                    addendIndex += startIndex.at(i);
                    break;
                }

                else if(i2 == startIndex.at(i) && down == 0)
                {
                    startpointIndex.removeAt(i);//肩峰情况,上升点移除后一个
                    break;
                }
            }
        }
    }

    //后肩峰，寄生峰分析
    if(endIndex.size()>1)
    {
        for(int i=1;i<endIndex.size();i++)
        {
            up = 0;
            for(i2 = endIndex.at(i-1);; i2++)
            {
                if(trand.at(i2) == 1)
                {
                    up = 1;
                    if(startIndex.contains(i2))
                        break;//无后肩峰，与未识别的寄生峰
                }

                else if(i2==endIndex.at(i)&&up==1)
                {  //有未被识别的后寄生峰,把第一个终点当作寄生峰终点
                    addstartIndex += endIndex.at(i-1);
                    addendIndex += endIndex.at(i);
                    break;
                }

                else if(i2 == endIndex.at(i) && up == 0)
                {
                    endpointIndex.removeAt(i-1);//肩峰情况,上升点移除上一个
                    break;
                }
            }
        }
    }

    //截取传递范围 (第一个峰起点到最后一个峰终点)
    int StartIndex_one;
    int EndIndex_one;
    StartIndex_one = startpointIndex.at(0);
    EndIndex_one = endpointIndex.at(endpointIndex.size() - 1);







    ////单峰半峰宽
//    FWHMcompute(point);
    int i,flag=0;
    double k,b,x;
    QList<QPointF> FittingLine;
    QList<QPointF> intermediary;
    QVector<double> pointX;
    double mid_value=(currentMaxValue - (currentData.at(startpointIndex.at(0)).y() + currentData.at(endpointIndex.at(0)).y()) / 2) / 2;

//    foreach (QPoint point, currentData) {
//        if (point)
//        {

//        }
//    }
    //8点
    for(i = startpointIndex.at(0); i < endpointIndex.at(0); i++)
    {
        if(currentData.at(i).y() > mid_value && i < currentmaxIndex && flag == 0)
        {
            intermediary << currentData.at(i - 2);
            intermediary << currentData.at(i - 1);
            intermediary << currentData.at(i);
            intermediary << currentData.at(i + 1);
            flag = 1;
        }

        if(currentData.at(i).y() < mid_value && i > currentmaxIndex)
        {
            intermediary << currentData.at(i-2);
            intermediary << currentData.at(i-1);
            intermediary << currentData.at(i);
            intermediary << currentData.at(i+1);     //按x轴顺序录入
            break;
        }
    }
    //4点
    for(i=0;i<intermediary.size();)
    {
        if(qAbs(intermediary.at(i).y() - mid_value) < qAbs(intermediary.at(i+2).y() - mid_value))
            FittingLine << intermediary.at(i) << intermediary.at(i+1);
        else if(qAbs(intermediary.at(i+3).y() - mid_value) < qAbs(intermediary.at(i+1).y() - mid_value))
            FittingLine << intermediary.at(i+2) << intermediary.at(i+3);
        else
            FittingLine << intermediary.at(i+1) << intermediary.at(i+2);
        i += 4;
    }

    //两条拟合直线，两个点
    for(i = 0; i < FittingLine.size();)
    {
        k = (FittingLine.at(i).y() - FittingLine.at(i+1).y()) / (FittingLine.at(i).x() - FittingLine.at(i+1).x());
        b = FittingLine.at(i).y() - k * FittingLine.at(i).x();
        x = (mid_value-b) / k;
        pointX.push_back(x);
        i += 2;
    }
    //半峰宽值
    FWHM = pointX.at(1) - pointX.at(0);




    ////面积
//    PeakAreaCalculation(point);   //!!!
    double leve, a1, a2, h, TriangleArea;
    double startY = currentData.at(StartIndex_one).y();
    double startX = currentData.at(StartIndex_one).x();
    double endY = currentData.at(EndIndex_one).y();
    double endX = currentData.at(EndIndex_one).x();
    //单峰情况
    if(startY > endY)
    {
        leve = startY;
    }
    else
    {
        leve = endY;
    }
    TriangleArea=qAbs(startY - endY) * (endX - startX) / 2;
    for(int i2 = StartIndex_one;i2 <= EndIndex_one; i2++)
    {
        a1 = currentData.at(i2).y() - leve;
        a2 = currentData.at(i2 - 1).y() - leve;
        h = currentData.at(i2).x() - currentData.at(i2 - 1).x();
        Area += (a1+a2) * h / 2;
    }
    Area = Area - TriangleArea;
}

void Utils::systemSettingsInit()
{
    QString filePath = Utils::getSettingFilePath();
    if (filePath.isEmpty())
    {
        Utils::tipMessageBox("配置文件路径错误");
        return;
    }

    QFileInfo info(filePath);

    //已存在配置文件
    if (info.exists())
    {
        return;
    }

    //数据库
    DBParams db;
    writeSettings(&db);

    //UDP
    UdpParams udp;
    writeSettings(&udp);

    //数据入库参数配置
    DBInsertParams dbInsert;
    writeSettings(&dbInsert);
}

QString Utils::getSettingFilePath()
{
    QString filePath = QDir::currentPath();

    if (!filePath.isEmpty())
    {
        filePath.append("/Settings.ini");
    }

    return filePath;
}

void Utils::readSettings(Params *data)
{
    QString filePath = getSettingFilePath();
    QSettings settings(filePath, QSettings::IniFormat);

    if (settings.childGroups().contains(data->groupName))
    {
        settings.beginGroup(data->groupName);
        for (int i = 0; i < data->nameList.size(); i++)
        {
            data->valueList[i] = settings.value(data->nameList.at(i));
        }
        settings.endGroup();
        data->isSucess = true;
        return;
    }

    data->isSucess = false;
}

void Utils::writeSettings(Params *data)
{
    QString filePath = getSettingFilePath();
    QSettings settings(filePath, QSettings::IniFormat);

    settings.beginGroup(data->groupName);
    int lenth = data->nameList.size();
    for (int i = 0; i < lenth; i ++)
    {
        settings.setValue(data->nameList.at(i), data->valueList.at(i));
    }

    settings.endGroup();
}
