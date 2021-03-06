//
//  ACRCloud_Config.h
//  ACRCloud_IOS_SDK
//
//  Created by olym on 15/3/25.
//  Copyright (c) 2015年 ACRCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    rec_mode_remote = 0,
    rec_mode_local = 1
}ACRCloudRecMode;

typedef enum {
    result_type_error = -1,
    result_type_none = 0,
    result_type_audio = 1,
    result_type_live = 2,
    result_type_audio_live = 3,
}ACRCloudResultType;

typedef enum {
    http_resume_type_error = -1,
    http_resume_type_resume = 0,
    http_resume_type_restart = 1
} HTTPResumeType;

#define ACRCLOUD_VERSION @"1.0"
#define MAX_REC_DATA 240000

typedef void(^ACRCloudResultBlock)(NSString *result, ACRCloudResultType resMode);

typedef void(^ACRCloudStateBlock)(NSString *state);

typedef void(^ACRCloudVolumeBlock)(float volume);

@interface ACRCloudConfig : NSObject
{
    NSString *_accessKey;
    NSString *_accessSecret;
    NSString *_host;
    NSString *_audioType;
    NSString *_homedir;
    NSDictionary *_params;
    ACRCloudRecMode _recMode;
    int _requestTimeout;
    ACRCloudResultBlock _resultBlock;
    ACRCloudStateBlock _stateBlock;
    ACRCloudVolumeBlock _volumeBlock;
}


@property(nonatomic, retain) NSString *accessKey;
@property(nonatomic, retain) NSString *accessSecret;
@property(nonatomic, retain) NSString *host;
@property(nonatomic, retain) NSString *audioType;
@property(nonatomic, retain) NSString *homedir;
@property(nonatomic, retain) NSDictionary *params;
@property(nonatomic, assign) ACRCloudRecMode recMode;
@property(nonatomic, assign) int requestTimeout;
@property(nonatomic, copy) ACRCloudResultBlock resultBlock;
@property(nonatomic, copy) ACRCloudStateBlock stateBlock;
@property(nonatomic, copy) ACRCloudVolumeBlock volumeBlock;

@end
