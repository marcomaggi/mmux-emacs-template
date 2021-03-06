;;; mmux-emacs-template.el --- template module

;; Copyright (C) 2020 Marco Maggi

;; Author: Marco Maggi <mrc.mgg@gmail.com>
;; Created: Sun Jan 12, 2020
;; Time-stamp: <2020-01-28 16:04:07 marco>
;; Keywords: extensions

;; This file is part of MMUX Emacs Template.
;;
;; This program is  free software: you can redistribute  it and/or modify it under the  terms of the
;; GNU General Public License as published by the  Free Software Foundation, either version 3 of the
;; License, or (at your option) any later version.
;;
;; This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
;; even the implied  warranty of MERCHANTABILITY or  FITNESS FOR A PARTICULAR PURPOSE.   See the GNU
;; General Public License for more details.
;;
;; You should have  received a copy of the  GNU General Public License along with  this program.  If
;; not, see <http://www.gnu.org/licenses/>.
;;

;;; Commentary:

;;

;;; Change Log:

;;

;;; Code:

(require 'cl-lib)
(eval-when-compile
  (load "libmmux-emacs-template"))
(load "libmmux-emacs-template")

(define-error 'mmux-template-error
  "Error while executing a MMUX Emacs Template operation."
  'error)

(define-error 'mmux-template-no-memory-error
  "Error allocating memory."
  'mmux-template-error)

(cl-defstruct (mmux-template-cplx (:constructor make-mmux-template-cplx))
  obj)

(defun mmux-template-make-cplx (X Y)
  "Build and return a new `mmux-temlate-cplx' object."
  (make-mmux-template-cplx :obj (mmux-template-c-cplx-make X Y)))

(defun mmux-template-get-X (obj)
  "Return the X component of an object of type `mmux-template-cplx'."
  (cl-assert (mmux-template-cplx-p obj))
  (mmux-template-c-cplx-get-X (mmux-template-cplx-obj obj)))

(defun mmux-template-get-Y (obj)
  "Return the Y component of an object of type `mmux-template-cplx'."
  (cl-assert (mmux-template-cplx-p obj))
  (mmux-template-c-cplx-get-Y (mmux-template-cplx-obj obj)))

(provide 'mmux-emacs-template)

;;; mmux-emacs-template.el ends here
