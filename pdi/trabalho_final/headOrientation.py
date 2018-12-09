from math import atan2, cos, sin, sqrt, pi
import numpy as np
import cv2 as cv
import sys

def drawAxis(img, p_, q_, colour, scale):
    p = list(p_)
    q = list(q_)

    angle = atan2(p[1] - q[1], p[0] - q[0])  # angle in radians
    hypotenuse = sqrt((p[1] - q[1]) * (p[1] - q[1]) + (p[0] - q[0]) * (p[0] - q[0]))

    # Here we lengthen the arrow by a factor of scale
    q[0] = p[0] - scale * hypotenuse * cos(angle)
    q[1] = p[1] - scale * hypotenuse * sin(angle)
    cv.line(img, (int(p[0]), int(p[1])), (int(q[0]), int(q[1])), colour, 1, cv.LINE_AA)

    # create the arrow hooks
    p[0] = q[0] + 9 * cos(angle + pi / 4)
    p[1] = q[1] + 9 * sin(angle + pi / 4)
    cv.line(img, (int(p[0]), int(p[1])), (int(q[0]), int(q[1])), colour, 1, cv.LINE_AA)

    p[0] = q[0] + 9 * cos(angle - pi / 4)
    p[1] = q[1] + 9 * sin(angle - pi / 4)
    cv.line(img, (int(p[0]), int(p[1])), (int(q[0]), int(q[1])), colour, 1, cv.LINE_AA)

def getOrientation(pts, img):
    # Construct a buffer used by the pca analysis
    sz = len(pts)
    data_pts = np.empty((sz, 2), dtype=np.float64)

    for i in range(data_pts.shape[0]):
        data_pts[i, 0] = pts[i, 0, 0]
        data_pts[i, 1] = pts[i, 0, 1]

    # Perform PCA analysis
    mean = np.empty((0))
    mean, eigenvectors, eigenvalues = cv.PCACompute2(data_pts, mean)

    # Store the center of the object
    cntr = (int(mean[0, 0]), int(mean[0, 1]))

    # Draw the principal components
    cv.circle(img, cntr, 3, (255, 0, 255), 2)
    p1 = (
        cntr[0] + 0.02 * eigenvectors[0, 0] * eigenvalues[0, 0], 
        cntr[1] + 0.02 * eigenvectors[0, 1] * eigenvalues[0, 0]
    )
    p2 = (
        cntr[0] - 0.02 * eigenvectors[1,0] * eigenvalues[1,0], 
        cntr[1] - 0.02 * eigenvectors[1,1] * eigenvalues[1,0]
    )

    drawAxis(img, cntr, p1, (0, 255, 0), 2)
    drawAxis(img, cntr, p2, (255, 255, 0), 5)

    # orientation in radians
    angle = atan2(eigenvectors[0, 1], eigenvectors[0, 0])
    return angle

if __name__ == '__main__':
    try:
        video = sys.argv[1]
        bg = sys.argv[2]
    except:
        print('Missing arguments!\nUsage: seg.py <video> <bg_image>')
        exit()

    bg_img = cv.imread(bg)

    if(bg_img.size is None):
        print('Error opening backgroung image')
        exit()

    cap = cv.VideoCapture(video)

    if (not cap.isOpened()):
        print('Error opening video stream')
        exit()

    mask_win = "Mask"
    cv.namedWindow(mask_win, cv.WINDOW_KEEPRATIO)
    cv.resizeWindow(mask_win, 450, 375)

    result_win = "Result"
    cv.namedWindow(result_win, cv.WINDOW_KEEPRATIO)
    cv.resizeWindow(result_win, 450, 375)
    cv.moveWindow(result_win, 453, 0)

    # Color range of the mice un the subtracted image
    lower_white = np.array([100, 100, 100])
    upper_white = np.array([160, 160, 160])

    while(cap.isOpened()):
        ret, frame = cap.read()

        if(not ret):
            print('Error readning video stream')
            exit()

        sub_frame = cv.absdiff(frame, bg_img)
       
        filtered_frame = cv.inRange(sub_frame, lower_white, upper_white)

        # Kernel for morphological operation opening
        kernel3 = cv.getStructuringElement(
            cv.MORPH_ELLIPSE,
            (3, 3),
            (-1, -1)
        )

        kernel20 = cv.getStructuringElement(
            cv.MORPH_ELLIPSE,
            (20, 20),
            (-1, -1)
        )

        # Morphological opening
        mask = cv.dilate(cv.erode(filtered_frame, kernel3), kernel20)

        # Find all the contours in the mask
        _, contours, _ = cv.findContours(
            mask, cv.RETR_LIST, cv.CHAIN_APPROX_NONE)

        for i, c in enumerate(contours):
            # Calculate the area of each contour
            area = cv.contourArea(c)

            # Ignore contours that are too small or too large
            if area < 1e2 or 1e5 < area:
                continue

            # Draw each contour only for visualisation purposes
            cv.drawContours(frame, contours, i, (255, 0, 255), 2)

            # Find the orientation of each shape
            getOrientation(c, frame)

        cv.imshow(result_win, frame)
        cv.imshow(mask_win, mask)

        key = cv.waitKey(5)
        if(key == 27):
            cv.destroyAllWindows()
            cap.release()
            exit()
        if(key == 32):
            while True:
                cv.imshow(result_win, frame)
                cv.imshow(mask_win, mask)

                key2 = cv.waitKey(5)
                if(key2 == 32):
                    break
                elif(key2 == 27):
                    cv.destroyAllWindows()
                    cap.release()
                    exit()
