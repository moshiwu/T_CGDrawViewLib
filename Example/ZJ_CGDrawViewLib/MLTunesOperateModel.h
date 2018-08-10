//
//  MLTunesOperateModel.h
//  pianoteiphone
//
//  Created by Doris on 17/1/9.
//  Copyright © 2017年 阎. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TunesOperateType)
{
    ServerTryConnect,//连接 0
    TODrawing,//绘制线 1
    TOTouchMeasure,//点击小节 2
    TOScrolling,//滑动曲谱 3
    TOChangeScale,//放大缩小曲谱 4
    TOClearAllDraw,//清除所有 5
    TOChangeTunes,//换曲谱(访问接口uid不同) 6
    TOStudentInRoom,//获得学生进入房间 7
    TOTeacherInRoom,//获得老师进入房间 8
    TOStudentOutRoom,//获得学生退出房间 9
    TOTeacherOutRoom,//获得老师退出房间 10
    TONoteStuChangeVideoFrame,//通知学生改变教师端视频尺寸 11
    TOStartRecodVideo,//开始录制 12
    TOStopRecordVido,//结束录制 13
    TOBeginPlayBack,//开始回放 14(废弃)
    TORecordFail,//开始录制失败 15
    TOStopRecordFail,//结束录制失败 16
    TOSetMetronomeSoundOn,//设置节拍器声音开始播放 17
    TOSetMetronomeSoundOff,//设置节拍器声音停止播放 18
    TOSetClientCanDraw,//设置学生可以开始绘图/取消绘图 19
    TONoteTeacherDrawing,//学生发给老师绘制的图形 20
    TODoubleClickReset,//学生受到老师曲谱图片双击还原
    TOChangeScoreImageScale,//学生受到老师设置图片缩放尺寸和位置
    TOCameraIsOn,
    TOCameraIsOff
};


//必须是对象类型 否则解析字典时会多
@interface MLTunesOperateModel : NSObject
@property (nonatomic,assign) TunesOperateType tunesOperate;/**< 操作类型*/
@property (nonatomic,strong) NSString * cameraMac;

@property (nonatomic,strong) NSString *sendStatus;//0-正常发 1-进入教室还原发
@property (nonatomic,strong) NSNumber *number;/**< 在线人数*/
@property (nonatomic,strong) NSString *recordStatus;//1-已经开始录制 0-没有录制

//画线or擦除
@property (nonatomic, strong) NSArray * pointList;
@property (nonatomic, strong) NSNumber * paintColorCount;
@property (nonatomic, strong) NSNumber * paintWidth;
@property (nonatomic, strong) NSNumber * isEraser;
@property (nonatomic, strong) NSNumber * shapeType;
@property (nonatomic,strong) NSNumber *brushColorCount; //画笔颜色
//@property (nonatomic, copy) NSString * action;
//@property (nonatomic, strong) NSNumber * width;
//@property (nonatomic, strong) NSNumber * height;

//点击曲谱
@property (nonatomic,strong) NSNumber *measureId;/**< 点击小节*/
@property (nonatomic,strong) NSArray *selectMeasureIdArr;/**< 选中小节数组*/
@property (nonatomic,strong) NSNumber *isCancel;/**< 是否取消点击恢复颜色*/


//滑动曲谱
@property (nonatomic,strong) NSNumber *offsetY;/**< 滑动曲谱*/

//缩放按钮
@property (nonatomic,strong) NSNumber *fontSize;/**<缩放字号*/

//换曲谱
@property (nonatomic, copy) NSString * songId;

//老师Id
@property (nonatomic, copy) NSString * teacherId;

//TONoteStuChangeVideoFrame
@property (nonatomic, strong) NSNumber *isBig;

//开始录制和结束录制时间戳(YYYY-MM-dd HH:mm:ss)
@property (nonatomic, copy) NSString * dateStr;

//TORecordFail
@property (nonatomic, strong) NSNumber *errorCode;
@property (nonatomic, strong) NSString *roleType;

//TOSetMetronomeSoundOn/TOSetMetronomeSoundOff
@property (nonatomic, strong) NSNumber *metronomeSpeed;

//TOSetClientCanDraw
@property (nonatomic, strong) NSString *pencilStatus;//0-隐藏画笔 1-显示画笔

@property (nonatomic,strong) NSNumber *scoreOffsetX;
@property (nonatomic,strong) NSNumber *scoreOffsetY;
@property (nonatomic,strong) NSNumber *scoreWidth;
@property (nonatomic,strong) NSNumber *scoreHeight;

@property (nonatomic,strong) NSNumber *minCanvasPointY;
@property (nonatomic,strong) NSNumber *canvasBackImageY;
@end
