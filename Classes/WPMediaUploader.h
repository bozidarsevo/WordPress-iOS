//
//  WPMediaUploader.h
//  WordPress
//
//  Created by Chris Boyd on 8/3/10.
//  Copyright 2010 WordPress. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BlogDataManager.h"

@interface WPMediaUploader : UIViewController {
	IBOutlet UILabel *messageLabel;
	IBOutlet UIProgressView *progressView;
	
	MediaType mediaType;
	MediaOrientation orientation;
	NSString *filename, *xmlrpcURL, *xmlrpcHost;
	NSData *bits;
	float filesize;
	
	NSURLConnection *connection;
	NSURLRequest *urlRequest;
	NSURLResponse *urlResponse;
	NSMutableData *payload;
}

@property (nonatomic, retain) IBOutlet UILabel *messageLabel;
@property (nonatomic, retain) IBOutlet UIProgressView *progressView;
@property (nonatomic, assign) MediaType mediaType;
@property (nonatomic, retain) NSString *filename, *xmlrpcURL, *xmlrpcHost;
@property (nonatomic, assign) float filesize;
@property (nonatomic, assign) MediaOrientation orientation;
@property (nonatomic, retain) NSData *bits;
@property (nonatomic, retain) NSURLConnection *connection;
@property (nonatomic, retain) NSURLRequest *urlRequest;
@property (nonatomic, retain) NSURLResponse *urlResponse;
@property (nonatomic, retain) NSMutableData *payload;

- (void)start;
- (void)stop;
- (void)reset;
- (void)connection:(NSURLConnection *)conn didReceiveResponse:(NSURLResponse *)response;
- (void)connection:(NSURLConnection *)conn didReceiveData:(NSData *)data;
- (void)connectionDidFinishLoading:(NSURLConnection *)conn;
- (void)connection:(NSURLConnection *)conn didFailWithError:(NSError *)error;
- (void)connection:(NSURLConnection *)connection didSendBodyData:(NSInteger)bytesWritten totalBytesWritten:(NSInteger)totalBytesWritten totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite;
- (void)createURLRequest:(XMLRPCRequest *)xmlrpc;

@end
