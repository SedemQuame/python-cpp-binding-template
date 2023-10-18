from flask import Flask, render_template, request, jsonify, Response
from werkzeug.utils import secure_filename
import ImageManipulation
import os
import uuid

app = Flask(__name__)

ALLOWED_EXTENSIONS = {"png", "jpg", "jpeg", "gif"}
UPLOAD_FOLDER = "/app/src/py/static/images"
app.config["UPLOAD_FOLDER"] = UPLOAD_FOLDER


def allowed_file(filename):
    return "." in filename and filename.rsplit(".", 1)[1].lower() in ALLOWED_EXTENSIONS


@app.route("/upload_image", methods=["POST"])
def upload_image():
    uploaded_file = request.files["file"]
    print(uploaded_file)

    if uploaded_file and allowed_file(uploaded_file.filename):
        save_path = os.path.join(app.config["UPLOAD_FOLDER"], uploaded_file.filename)
        directory = os.path.dirname(save_path)
        if not os.path.exists(directory):
            os.makedirs(directory)
        uploaded_file.save(save_path)
        web_img_path = save_path.replace("/app/src/py", ".")
        return (
            jsonify({"message": "File uploaded successfully!", "path": web_img_path}),
            200,
        )

    return (jsonify({"message": "Failed to upload file."}), 400)


@app.route("/<effect>", methods=["POST"])
def apply_effect(effect):
    image_path = os.path.join(request.form["imagePath"])
    _image_path = image_path.replace("./static", "/app/src/py/static").split("?")[0]

    try:
        if effect == "grayscale":
            ImageManipulation.convertImageToGray(_image_path)
        elif effect == "brightness":
            ImageManipulation.changeImageBrightness(_image_path, 50)
        elif effect == "contrast":
            ImageManipulation.changeImageContrast(_image_path, 10)
        elif effect == "histogram":
            ImageManipulation.equalizeImageHistogram(_image_path)
        elif effect == "homogeneousBlur":
            ImageManipulation.homogeneousBlur(_image_path, 5)
        elif effect == "gaussianBlur":
            ImageManipulation.gaussianBlur(_image_path, 5)
        elif effect == "invertImage":
            ImageManipulation.invertImage(_image_path)
        elif effect == "erodeImage":
            ImageManipulation.erodeImage(_image_path, 4)
        elif effect == "rotateImage":
            ImageManipulation.rotateImage(_image_path, 90)
        else:
            return jsonify({"message": f"Effect {effect} not recognized."}), 400

        return (
            jsonify({"message": f"{effect} applied successfully!", "path": image_path}),
            200,
        )
    except Exception as e:
        return jsonify({"message": f"Error applying {effect}.", "error": str(e)}), 500


@app.route("/")
def index():
    return render_template("index.html")


@app.errorhandler(404)
def not_found(e):
    return jsonify({"message": "Resource not found."}), 404


@app.errorhandler(500)
def internal_error(e):
    return jsonify({"message": "An internal error occurred."}), 500


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5001, debug=True)
