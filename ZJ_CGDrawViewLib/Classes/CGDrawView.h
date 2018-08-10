//
//  CGDrawView.h
//  CGDrawView
//
//  Created by Doris on 2018/4/12.
//  Copyright © 2018年 Doris. All rights reserved.
//

#import <UIKit/UIKit.h>

#define MAX_UNDO_COUNT   10

#define LSDEF_BRUSH_COLOR [UIColor colorWithRed:255 green:0 blue:0 alpha:1.0]

#define LSDEF_BRUSH_WIDTH 3

#define LSDEF_BRUSH_SHAPE LSShapeCurve

#define MLPercent (([UIScreen mainScreen].bounds.size.width)<([UIScreen mainScreen].bounds.size.height)?([UIScreen mainScreen].bounds.size.width/768):([UIScreen mainScreen].bounds.size.height/768))
#define DefaultOneH (1*MLPercent<=0.5 ?0.5:1*MLPercent)

//画笔形状
typedef NS_ENUM(NSInteger, LSShapeType)
{
    LSShapeCurve = 0,//曲线(默认)
    LSShapeLine,//直线
    LSShapeEllipse,//椭圆
    LSShapeRect,//矩形
    
};
/////////////////////////////////////////////////////////////////////

//封装的画笔类
@interface LSBrush: NSObject

//画笔颜色
@property (nonatomic, strong) UIColor *brushColor;

//画笔宽度
@property (nonatomic, assign) NSInteger brushWidth;

//是否是橡皮擦
@property (nonatomic, assign) BOOL isEraser;

//形状
@property (nonatomic, assign) LSShapeType shapeType;

//路径
@property (nonatomic, strong) UIBezierPath *bezierPath;

//起点
@property (nonatomic, assign) CGPoint beginPoint;
//终点
@property (nonatomic, assign) CGPoint endPoint;

@end

#import "MLTunesOperateModel.h"
@protocol CGDrawViewDelegate <NSObject>
- (void)toDrawingWithModel:(MLTunesOperateModel *)model;
- (void)toClearAllWithModel:(MLTunesOperateModel *)model;
@end

@interface CGDrawView : UIScrollView
@property (nonatomic,assign) CGFloat contentH;/**< 曲谱长度*/
@property (nonatomic,assign) CGFloat contentOffetY;/**< 曲谱偏移值*/

@property (nonatomic,weak) id<CGDrawViewDelegate> ldDelegate;
//颜色
@property (strong, nonatomic) UIColor *brushColor;
@property (strong, nonatomic) UIColor *receiveBrushColor;
//调色板
@property (nonatomic,strong,readonly) UIImageView *colorsView;
//是否是橡皮擦
@property (assign, nonatomic) BOOL isEraser;
@property (assign, nonatomic) BOOL receiveIsEraser;
//宽度
@property (assign, nonatomic) NSInteger brushWidth;
@property (assign, nonatomic) NSInteger receiveBrushWidth;
//形状
@property (assign, nonatomic) LSShapeType shapeType;
@property (assign, nonatomic) LSShapeType receiveShapeType;
//背景图
@property (assign, nonatomic) UIImage *backgroundImage;

@property (nonatomic, assign) BOOL isCanDraw;//Y-可绘图,isEraser后赋值
@property (nonatomic,strong) NSString * roleType;//t-老师 s-学生

@property (nonatomic,strong) NSString *roomId;
@property (nonatomic,strong) NSNumber *scoreScrollOffsetY;//绘制时,学生端可能滑动曲谱了,应恢复
@property (nonatomic, assign) BOOL isMsgiRoom;

//保存到相册
- (void)save;
//清除绘制
- (void)clearWithIsSend:(BOOL)isSend;

-(void)setIsCanDraw:(BOOL)canDraw;

- (void)drawWithLineModel:(MLTunesOperateModel *)model;

- (void)setDefault;
@property (nonatomic,assign) CGRect scoreFrame;/**< */

@end

