//
//  UIView+EXCategory.h
//  Elex
//
//  Created by 沈丰元 on 2017/9/7.
//  Copyright © 2017年 沈丰元. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (EXCategory)
@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGFloat centerX;
@property (nonatomic, assign) CGFloat centerY;
@property (nonatomic, assign) CGFloat maxX;
@property (nonatomic, assign) CGFloat maxY;
/** 从xib中创建一个控件 */
+ (instancetype)viewFromXib;
//获取该视图的控制器
- (UIViewController*) viewController;

//删除当前视图内的所有子视图
- (void) removeChildViews;

//删除tableview底部多余横线
- (void)setExtraCellLineHidden: (UITableView *)tableView;
@end
