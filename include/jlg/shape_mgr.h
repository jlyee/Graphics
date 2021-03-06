
#if !defined(__JLG_SHAPE_MGR_HEADER__)
#define __JLG_SHAPE_MGR_HEADER__

#include"shape.h"

namespace jlg {
	class shape_mgr {
	public:
		shape_mgr();
		virtual void add_shape(GLuint& shape_id, const GLfloat* data, const GLuint& Dimensions, const GLuint& Count);
		virtual void add_shape(GLuint& shape_id, const shape& copy_shape);
		virtual void add_shape_attrib(const GLuint& shape_id, const GLuint& Count);
		virtual void buffer();
		virtual void draw() const;
	protected:
		std::vector<jlg::shape> _shapes;
		std::vector<GLuint> _buffer_objs;
		std::vector<GLuint> _vertex_buffer_array_objs;

	};
};

#endif