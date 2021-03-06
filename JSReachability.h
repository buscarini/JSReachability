/* 
 Copyright 2012 Javier Soto (ios@javisoto.es)
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License. 
 */

extern NSString * const JSReachabilityHostReachabilityDidChangeNotification;
extern NSString * const JSReachabilityNotificationHostUserInfoKey;

@protocol JSReachabilityDelegate;

@interface JSReachability : NSObject

@property (nonatomic, assign, readonly) BOOL hostIsReachable;
@property (nonatomic, assign) id<JSReachabilityDelegate> delegate;

/**
 * @param host (required) the host to monitor whether it's reachable or not.
 * @param delegate (optional). Pass `nil` if you just want to use the NSNotificationCenter approach.
 */
+ (JSReachability *)reachabilityWithHost:(NSString *)host
                                delegate:(id<JSReachabilityDelegate>)delegate;

/**
 * @discussion doesn'in case you're not interested in a particular host.
 * @param delegate (optional). Pass `nil` if you just want to use the NSNotificationCenter approach.
 */
+ (JSReachability *)reachabilityForInternetConnectionWithDelegate:(id<JSReachabilityDelegate>)delegate;

/**
 * @discussion Starts monitoring the provided host for reachability and calls the delegate with updates
 */
- (void)start;

/**
 * @discussion Stops monitoring the provided host for reachability and stops calling the delegate with updates
 */
- (void)stop;

@end

@protocol JSReachabilityDelegate <NSObject>

/**
 * @param reachability the object monitoring the reachability
 * @param host the host being monitored (the same as passed when initializing). May be nil if you're monitoring the internet connection.
 * @param reachable a boolean with whether the host is reachable or not
 * @discussion this method is called at least once when reachability starts monitoring with the initial value
 */
- (void)reachability:(JSReachability *)reachability host:(NSString *)host didBecomeReachable:(BOOL)reachable;

@end
