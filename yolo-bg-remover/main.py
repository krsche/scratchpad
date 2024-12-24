from rembg import remove
from ultralytics import YOLO
import ultralytics
import cv2

model = YOLO('yolov8n.pt')
# model = YOLO('yolov8n-seg.pt')

results = model('./orig2.jpeg')
print(results)

if len(results) == 0:
    print("Nothing detected")
    exit()

annotated_frame = results[0].plot()
cv2.imwrite("output.jpg", annotated_frame)

boxes: ultralytics.engine.results.Boxes = results[0].boxes
# print(boxes.xywh)
# x = int(boxes.xywh[0, 0])
# y = int(boxes.xywh[0, 1])
# w = int(boxes.xywh[0, 2])
# h = int(boxes.xywh[0, 3])
# print(boxes.xyxy)
x = int(boxes.xyxy[0, 0])
y = int(boxes.xyxy[0, 1])
x2 = int(boxes.xyxy[0, 2])
y2 = int(boxes.xyxy[0, 3])

print(x, y, x2, y2)

# orig_shape = results[0].orig_shape
# orig_y, orig_x, _ = orig_shape

# cropped_frame = results[0].orig_img[orig_y*y:orig_y*y+orig_y*h, orig_x*x:orig_x*x+orig_x*w]
# cropped_frame = results[0].orig_img[y:y+h, x:x+w]
im = cv2.imread('./orig.jpeg')
cropped_frame = im[y:y2, x:x2]
# cropped_frame = im[y:y+h, x:x+w]

cv2.imwrite("output_cropped.jpg", cropped_frame)

# -------------------------------------------
# rembg


input_path = 'output_cropped.jpg'
output_path = 'output_cropped_removed3.png'

with open(input_path, 'rb') as i:
    with open(output_path, 'wb') as o:
        input = i.read()
        # output = remove(input)
        # output = remove(input, post_process_mask=True)
        output = remove(input, alpha_matting=True)
        o.write(output)
