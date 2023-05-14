#pragma once

/// <summary>
/// Enumerates renderer state.
/// </summary>
enum class RendererState
{
	/// <summary>
	/// The renderer is initialising.
	/// </summary>
	Init = 0,

	/// <summary>
	/// The renderer has started and is waiting for a new frame.
	/// </summary>
	Start = 1,

	/// <summary>
	/// Backdrop objects like the skybox are being rendered.
	/// </summary>
	Backdrop = 2,

	/// <summary>
	/// Render objects are being rendered.
	/// </summary>
	RenderObjects = 3,

	/// <summary>
	/// Post-processing is being performed.
	/// </summary>
	PostProcessing = 4,

	/// <summary>
	/// Presentation is occurring.
	/// Return to start.
	/// </summary>
	Present = 5,
};