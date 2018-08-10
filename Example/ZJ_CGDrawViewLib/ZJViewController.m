//
//  ZJViewController.m
//  ZJ_CGDrawViewLib
//
//  Created by krystalNa on 08/10/2018.
//  Copyright (c) 2018 krystalNa. All rights reserved.
//

#import "ZJViewController.h"
#import <ZJ_CGDrawViewLib/CGDrawView.h>

@interface ZJViewController ()//<CGDrawViewDelegate>
@property (nonatomic,strong) CGDrawView *drawBoard;
@end

@implementation ZJViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
//    self.drawBoard = [[CGDrawView alloc] initWithFrame:self.view.bounds];
//    self.drawBoard.ldDelegate = self;
//    self.drawBoard.contentH = self.view.frame.size.height;
//
//    self.drawBoard.isEraser = NO;
//    self.drawBoard.isCanDraw = YES;
//
//    [self.drawBoard setDefault];
//    [self.view addSubview:self.drawBoard];
//
//    self.drawBoard.colorsView.frame = CGRectMake(0, 85*MLPercent, self.drawBoard.colorsView.frame.size.width, self.drawBoard.colorsView.frame.size.height);
//    [self.view addSubview:self.drawBoard.colorsView];
    
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
