import cv2
import os
import threading

def video_to_frames(video_path, outPutDirName):
    times = 0
    
    # ��ȡ��Ƶ��Ƶ�ʣ�ÿ2֡��ȡһ��
    frame_frequency = 2
    
	# ����ļ�Ŀ¼�������򴴽�Ŀ¼
    if not os.path.exists(outPutDirName):
        os.makedirs(outPutDirName)
        
    # ��ȡ��Ƶ֡
    camera = cv2.VideoCapture(video_path)
    
    while True:
        times = times + 1
        res, image = camera.read()
        if not res:
            print('error')
            break
        if times % frame_frequency == 0:
            cv2.imwrite(outPutDirName + '\\' + str(times)+'.jpg', image)
            
    print('end')
    camera.release()


if __name__ == "__main__":
    input_dir = r''                             # �����video�ļ���λ��
    save_dir = r''                              # ���ͼƬ����ǰĿ¼video�ļ�����
    count = 0                                   # ��Ƶ��
    for video_name in os.listdir(input_dir):
        video_path = os.path.join(input_dir, video_name)
        outPutDirName = os.path.join(save_dir, video_name[:-4])
        threading.Thread(target=video_to_frames, args=(video_path, outPutDirName)).start()
        count = count + 1
        print("%s th video has been finished!" % count)
