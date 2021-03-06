//
//  AIModel.h
//  SMG_NothingIsAll
//
//  Created by 贾  on 2017/12/5.
//  Copyright © 2017年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  MARK:--------------------Net.data的数据类型--------------------
 *  int     //from to algs
 *  float   //from to algs
 *  change  //from to
 *  file    //二进制文件
 *  char
 *  string  //char的pointer组成的数组
 *  mp3
 *  mp4
 *  imv     //所有imv定义的子类...
 *  参考:n9p9 n10p23
 */
@interface AIModel : NSObject<NSCoding>

-(NSString*) getDataType;

@end


//MARK:===============================================================
//MARK:                     < AIIntModel >
//MARK:===============================================================
@interface AIIntModel : AIModel

+(AIIntModel*) newWithFrom:(int)from to:(int)to;
@property (assign,nonatomic) int from;
@property (assign,nonatomic) int to;

@end

//MARK:===============================================================
//MARK:                     < AIFloatModel >
//MARK:===============================================================
@interface AIFloatModel : AIModel

+(AIFloatModel*) newWithFrom:(CGFloat)from to:(CGFloat)to;
@property (assign,nonatomic) CGFloat from;
@property (assign,nonatomic) CGFloat to;

@end

//MARK:===============================================================
//MARK:                     < AIChangeModel >
//MARK:===============================================================
@interface AIChangeModel : AIModel

@property (assign,nonatomic) CGFloat from;
@property (assign,nonatomic) CGFloat to;

@end


//MARK:===============================================================
//MARK:                     < AIFileModel >
//MARK:===============================================================
@interface AIFileModel : AIModel

@property (strong,nonatomic) NSData *file;

@end


//MARK:===============================================================
//MARK:                     < AICharModel >
//MARK:===============================================================
@interface AICharModel : AIModel

@property (assign,nonatomic) char c;

@end

//MARK:===============================================================
//MARK:                     < AIStringModel >
//MARK:===============================================================
@interface AIStringModel : AIModel

@property (strong,nonatomic) NSMutableArray *charPointers;//char的pointer组成的数组

@end

//MARK:===============================================================
//MARK:                     < AIArrayModel >
//MARK:===============================================================
@interface AIArrayModel : AIModel

@property (strong,nonatomic) NSMutableArray *itemPointers;//item的pointer组成的数组

@end

//MARK:===============================================================
//MARK:                     < AIIdentifierModel >
//MARK:===============================================================
@interface AIIdentifierModel : AIModel

+(AIIdentifierModel*) newWithIdentifier:(NSString*)identifier;
@property (strong,nonatomic) NSString *identifier;//自定义类类别标记(如AIImvAlgsModel)

@end


//MARK:===============================================================
//MARK:                     < AICMVModel >
//MARK:===============================================================
@interface AICMVModel : AIModel//1. startCMV  //2. endCMV


@property (assign, nonatomic)  NSInteger urgentValue; //经algs转化后的值;例如(饥饿状态向急切度的变化)
@property (assign, nonatomic) AITargetType targetType;


@end

