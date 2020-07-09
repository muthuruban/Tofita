// The Tofita Kernel
// Copyright (C) 2020  Oleg Petrenko
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, version 3 of the License.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// Desktop window manager (i.e. GUI logic)

namespace dwm {

uint64_t firstResponder = 0; // Active window to catch keyboard input

struct OverlappedWindow {
	bool present;
	uint64_t pid; // Owner
	// TODO tid - thread id
	uint64_t windowId;
	bool visible;
	const wchar_t *title;

	int16_t x;
	int16_t y;

	uint16_t width;
	uint16_t height;

	// fb.pixels == null if framebuffer not present
	// Note: fb size may be != current window size
	Bitmap32 *fbZeta;
	Bitmap32 *fbGama;
	bool fbCurrentZeta; // Use to swap chain
};

constexpr uint64_t windowsLimit = 256;

// TODO allocate dynamically (just use Hexa Array or something)
OverlappedWindow windowsList[windowsLimit];

OverlappedWindow *OverlappedWindow_create(uint64_t pid);
OverlappedWindow *OverlappedWindow_find(uint64_t pid, uint64_t windowId);
} // namespace dwm
