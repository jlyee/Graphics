
#if !defined(__JLG_VIEWER_HEADER__)
#define __JLG_VIEWER_HEADER__
#include"jlg/base/window.h"
#include "jlg/base/shape_mgr.h"
#include "jlg/shading/shading_mgr.h"


namespace jlg {
	class viewer {
	public:
		viewer(
			const GLuint& Width,
			const GLuint& Height,
			const GLchar* Title,
			const GLchar* Vertex_Shader_Path,
			const GLchar* Fragment_Shader_Path);
		virtual inline jlg::Window& window() { return _window; }
		virtual inline jlg::shape_mgr& shapes() { return _shapes; }
		virtual inline jlg::basic_shading_mgr& shader() { return _shader; }
		virtual inline void update() {
			_current_frame = glfwGetTime();
			_delta_time = _current_frame - _last_frame;
			jlg::camera_mgr::do_movement(_delta_time);
			_window.Render();
			_shader.apply();
			_shapes.draw();
			glfwSwapBuffers(_window.Handle());
			_last_frame = _current_frame;
		}
	protected:
		jlg::camera _camera;
		jlg::Window _window;
		jlg::shape_mgr _shapes;
		jlg::basic_shading_mgr _shader;
		GLfloat _current_frame;
		GLfloat _last_frame;
		GLfloat _delta_time;
	};


	class model_viewer {
	public:
		model_viewer(
			const GLuint& Width,
			const GLuint& Height,
			const GLchar* Title,
			const GLchar* Vertex_Shader_Path,
			const GLchar* Fragment_Shader_Path);
		virtual inline jlg::Window& window() { return _window; }
		virtual inline jlg::model_shading_mgr& shader() { return _shader; }
		virtual inline jlg::model_mgr& models() { return _models; }
		virtual inline void update() {
			_current_frame = glfwGetTime();
			_delta_time = _current_frame - _last_frame;
			jlg::camera_mgr::do_movement(_delta_time);
			_window.Render();
			_shader.apply();
			glfwSwapBuffers(_window.Handle());
			_last_frame = _current_frame;
		}
	protected:
		jlg::camera _camera;
		GLfloat _current_frame;
		GLfloat _last_frame;
		GLfloat _delta_time;
		jlg::Window _window;
		jlg::model_shading_mgr _shader;
		jlg::model_mgr _models;
	};

};


#endif